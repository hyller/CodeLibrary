//
// Settings.cpp --- Version builder settings implementation.
//
// Copyright (c) 2013 Paul Ward <asmodai@gmail.com>
//
// Time-stamp: <Saturday Jun  1, 2013 22:32:57 asmodai>
// Revision:   28
//
// Author:     Paul Ward <asmodai@gmail.com>
// Maintainer: Paul Ward <asmodai@gmail.com>
// Created:    30 May 2013 01:17:15
// Keywords:   
// URL:        not distributed yet
//
// {{{ License:
//
// This program is free software; you can redistribute it and/or
// modify it under the terms of the GNU General Public License
// as published by the Free Software Foundation; either version 3
// of the License, or (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program; if not, see  <http://www.gnu.org/licenses/>.
//
// }}}
// {{{ Commentary:
//
// }}}

/**
 * @file Settings.cpp
 * @author Paul Ward
 * @brief Command line parsing and program settings.
 */

#include <QtCore/QString>
#include <QtCore/QStringList>
#include <QtCore/QTextStream>

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#include "Settings.hpp"

#define _EXTERNAL_
#include "Formatter.hpp"
#undef _EXTERNAL_

/**
 * @brief Empty vector for convenience.
 *
 * TCLAP requires a constraint to have a constructor that takes a
 * vector of allowed values as an argument.  This constraint uses
 * custom logic to ascertain the validity of a value, thus there is
 * no need to define a vector of allowed values.
 */
std::vector<int> nullIntVec;

/**
 * @brief Empty vector for convenience.
 *
 * TCLAP requires a constraint to have a constructor that takes a
 * vector of allowed values as an argument.  This constraint uses
 * custom logic to ascertain the validity of a value, thus there is
 * no need to define a vector of allowed values.
 */
std::vector<std::string> nullStrVec;

/**
 * @brief Convert a @c std::string to a @c QString.
 * @param string The string to convert.
 * @returns A QString.
 */
static QString
fromStdString(std::string &string)
{
  return QString::fromUtf8(string.data(), (int)string.size());
}

/**
 * @brief Convert a @c const @c std::string to a @c QString.
 * @param string The string to convert.
 * @returns A QString.
 */
static QString
fromConstStdString(const std::string &string)
{
  return QString::fromUtf8(string.data(), (int)string.size());
}

/**
 * @brief Convert a @c bool value to a pretty @c QString.
 * @param value The boolean to convert.
 * @returns A QString containing either "true" or "false" depending on
 *          the value of the boolean.
 */
static QString
fromBool(const bool &value)
{
  return QString(value ? "true" : "false");
}

/**
 * @brief Return either a value from a QString or "<null>".
 * @param string The source QString.
 * @returns The sources value if it is not NULL; otherwise "<null>" is
 *          returned.
 */
static QString
valueOrNull(const QString &string)
{
  return QString(string.isNull() ? "<null>" : string);
}

/**
 * @brief Return either a value from a QString or "<empty>".
 * @param string The source QString.
 * @returns The sources value if it is not empty; otherwise "<empty>"
 *          is returned.
 */
static QString
valueOrEmpty(const QString &string)
{
  return QString(string.isEmpty() ? "<empty>" : string);
}



bool
FormatConstraint::check(const std::string &value) const
{
  QRegExp re(FRE);
  QString val(fromConstStdString(value));

  return re.exactMatch(val);
}


InitialValues nullInitial = { false, 0 };


Settings::Settings(int argc, char **argv)
{
  try {
    TCLAP::CmdLine cmd("", ' ', VERSION_STRING, true);
    std::string    fmtrMsg = std::string("Output formatter type: ");
    
    /* Constraint definitions. */
    FormatConstraint         allowedFmt(nullStrVec);
    YearConstraint           allowedYear(nullIntVec);
    std::vector<std::string> allowedGroupsVec;
    std::vector<std::string> allowedIncrsVec;
    std::vector<std::string> allowedFmatrsVec;
    
    /* Output group values. */
    allowedGroupsVec.push_back("basic");
    allowedGroupsVec.push_back("struct");
    allowedGroupsVec.push_back("doxygen");
    allowedGroupsVec.push_back("all");
    TCLAP::ValuesConstraint<std::string> allowedGroups(allowedGroupsVec);
    
    /* Incrementation constraint values. */
    allowedIncrsVec.push_back("simple");
    allowedIncrsVec.push_back("date");
    allowedIncrsVec.push_back("months");
    allowedIncrsVec.push_back("years");
    TCLAP::ValuesConstraint<std::string> allowedIncrs(allowedIncrsVec);
    
    /* Formatter constraint values. */
    {
      size_t cnt = FormatterFactory::size();

      for (FormatterFnMap::iterator it = FormatterFactory::begin();
           it != FormatterFactory::end();
           ++it)
      {
        allowedFmatrsVec.push_back(it->first);
        fmtrMsg += it->first + " = "
            + FormatterFactory::nameForFormatter(it->first);

        if (cnt > 1) {
          fmtrMsg += ", ";
        }
      }
    }
    TCLAP::ValuesConstraint<std::string> allowedFmtrs(allowedFmatrsVec);
    
    /* Arguments. */
    StringOpt fileName("o",
                       "output",
                       "File containing version information.",
                       false,
                       "",
                       "string");
    StringOpt verFmt("f",
                     "format",
                     "Version number format string.",
                     false,
                     "*.*.+.*",
                     &allowedFmt);
    IntOpt baseYear("y",
                    "base-year",
                    "The year the project was started.",
                    false,
                    0,
                    &allowedYear);
    StringOpt incrType("i",
                       "increment",
                       "Type of increment used.",
                       false,
                       "simple",
                       &allowedIncrs);
    TCLAP::SwitchArg overFlow("s",
                              "overflow",
                              "Perform overflow checking and shifting.",
                              false);
    TCLAP::SwitchArg verbose("v",
                             "verbose",
                             "Verbose output.",
                             false);
    TCLAP::SwitchArg createFile("c",
                                "create",
                                "Create the output file if it does not exist.",
                                false);
    StringOpt formatter("t",
                        "formatter",
                        fmtrMsg,
                        true,
                        "",
                        &allowedFmtrs);
    TCLAP::MultiArg<std::string> groups("g",
                                        "groups",
                                        "Output groups generated.",
                                        false,
                                        &allowedGroups);
    StringOpt outPref("p",
                      "prefix",
                      "String to prepend to symbols created by the formatter.",
                      false,
                      "",
                      "string");
    
    /* Add them in reverse alphabetic order. */
    cmd.add(baseYear);          // y
    cmd.add(verbose);           // v
    cmd.add(formatter);         // t
    cmd.add(overFlow);          // s
    cmd.add(outPref);           // p
    cmd.add(fileName);          // o
    cmd.add(incrType);          // i
    cmd.add(groups);            // g
    cmd.add(verFmt);            // f
    cmd.add(createFile);        // c
    cmd.parse(argc, argv);
    
    /* Fill the static vector here. */
    m_static.fill(nullInitial, 4);
    
    /* Extract the options. */
    m_filePath     = fromStdString(fileName.getValue());
    m_format       = fromStdString(verFmt.getValue());
    m_formatter    = fromStdString(formatter.getValue());
    m_baseYear     = baseYear.getValue();
    m_overflow     = overFlow.getValue();
    m_verbose      = verbose.getValue();
    m_createFile   = createFile.getValue();
    m_groups       = groups.getValue();
    m_outputPrefix = fromStdString(outPref.getValue());

    /* Extract the incrementation type. */
    if (incrType.getValue().compare("date") == 0) {
      m_incrType = BuildByDate;
    } else if (incrType.getValue().compare("months") == 0) {
      m_incrType = BuildByMonths;
    } else if (incrType.getValue().compare("years") == 0) {
      m_incrType = BuildByYears;
    } else {
      m_incrType = BuildSimple;
    }
    
    /* Are we to use stdout? */
    if (m_filePath.isNull() || m_filePath.length() == 0)
    {  
      m_useStdOut = true;
    } else {
      m_useStdOut = false;
    }
  }
  
  catch (TCLAP::ArgException &e) {
    std::cerr << "Error: " << e.error()
              << " for arg " << e.argId()
              << std::endl;
  }
}                               // Settings::Settings()

const Increments
Settings::incrementFields(void)
{
  QStringList segments = m_format.split('.');
  Increments  ret      = 0;

  for (int i = 0; i < 4; ++i) {
    if (segments.at(i).compare("+") == 0) {
      /*
       * Increment... now compute which segment.
       */
      switch (i) {
        case 0: ret |= IncrementMajor; break;
        case 1: ret |= IncrementMinor; break;
        case 2: ret |= IncrementBuild; break;
        case 3: ret |= IncrementPatch; break;
      }
    } else {
      /*
       * Not incrementing... but do we use a constant value?
       */
      if (segments.at(i).compare("*") != 0) {
        /*
         * Yes, we're using a constant value.
         */
        unsigned int val;
        bool         ok;
        
        val = segments.at(i).toUInt(&ok, 10);
        
        if (ok) {
          m_static[i].use = true;
          m_static[i].value = val;
        }
      }
      
      /*
       * Well, given we're not incrementing, doesn't matter if we're
       * keeping the existing value or using a constant value, we
       * don't want to increment... unset the right bits.
       */
      switch (i) {
        case 0: ret &= ~IncrementMajor; break;
        case 1: ret &= ~IncrementMinor; break;
        case 2: ret &= ~IncrementBuild; break;
        case 3: ret &= ~IncrementPatch; break;
      }
    }
  }
  
  return ret;
}

OutputFlags Settings::outputFlags(void) const
{
  OutputFlags ret;
  
  for (std::vector<std::string>::const_iterator it = m_groups.begin();
       it != m_groups.end();
       ++it)
  {
    if ((*it).compare("basic") == 0) {
      ret |= OutputBasic;
    } else if ((*it).compare("struct") == 0) {
      ret |= OutputStruct;
    } else if ((*it).compare("doxygen") == 0) {
      ret |= OutputDoxygen;
    } else if ((*it).compare("all") == 0) {
      ret |= OutputAll;
    }
  }
  
  if (ret == 0) {
    qFatal("No output groups specified. Aborting...");
  }

  return ret;
}

void
Settings::dump(void) const
{
  QTextStream out(stdout);
  QString     incrType = QString();
  QStringList tmp;

  for (std::vector<std::string>::const_iterator it = m_groups.begin();
       it != m_groups.end();
       ++it) {
    tmp << fromConstStdString(*it);
  }
  
  switch (m_incrType) {
    case BuildByMonths: incrType = QString("Months"); break;
    case BuildByYears:  incrType = QString("Years");  break;
    case BuildByDate:   incrType = QString("Date");   break;
    case BuildSimple:   incrType = QString("Simple"); break;
  }

  out << endl << "Settings:" << endl << endl
      << "    Output formatter: " << m_formatter << endl
      << "       Output groups: " << tmp.join(", ") << endl
      << "      Version format: " << m_format << endl
      << "      Increment type: " << incrType << endl
      << "           File name: " << valueOrEmpty(m_filePath) << endl
      << "           Base year: " << m_baseYear << endl
      << "       Output prefix: " << m_outputPrefix << endl
      << "  Create output file? " << fromBool(m_createFile) << endl
      << "   Overflow shifting? " << fromBool(m_overflow) << endl
      << "        Using stdout? " << fromBool(m_useStdOut) << endl
      << endl;
}

// Settings.cpp ends here
