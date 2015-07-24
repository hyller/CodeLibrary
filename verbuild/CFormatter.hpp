//
// CFormatter.hpp --- C/C++ header input and output.
//
// Copyright (c) 2013 Paul Ward <asmodai@gmail.com>
//
// Time-stamp: <Saturday Jun  1, 2013 22:39:40 asmodai>
// Revision:   86
//
// Author:     Paul Ward <asmodai@gmail.com>
// Maintainer: Paul Ward <asmodai@gmail.com>
// Created:    29 May 2013 04:19:38
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
// along with this program; if not, see <http://www.gnu.org/licenses/>.
//
// }}}
// {{{ Commentary:

// }}}

#ifndef __CFormatter_hpp__
#define __CFormatter_hpp__

/**
 * @file CFormatter.hpp
 * @author Paul Ward
 * @brief Outputs version information to C/C++ header files.
 */

#define _EXTERNAL_
#include "Formatter.hpp"
#undef _EXTERNAL_

#define C_PRETTY "C/C++"

/**
   @def DRE
   @brief Regular expression to find 'VERSION_' definitions in C/C++
          headers.
 
   This regular expression is designed to match the second portion of
   the definition name and its value, e.g.
   @code{.cpp}
   #define VERSION_MAJOR     24
   @endcode
   will result in two match groups: @em MAJOR and @em 24.
 */
#define DRE                                     \
  "(?:VERSION[_])(\\w+)(?:\\s+)(\\d+)"

/**
   @def SRE
   @brief Regular expression to find the C structure definition for
          the version information.
   
   Each component of the structure instance will be contaned in a
   match group, e.g.
   @code{.cpp}
   static struct VersionNumber_s {
     int baseYear;
     int major;
     int minor;
     int patch;
     int build;
   } VersionNumber = {
     1983,
     10,
     5,
     8,
     36530
   };
   @endcode
   will result in five match groups: @em 1983, @em 10, @em 5, @em 8,
   and @em 36530.
 */
#define SRE                                             \
  "(?:[{]\\s*)(\\d+)(?:[,]\\s+)(\\d+)(?:[,]\\s+)(\\d+)" \
  "(?:[,]\\s+)(\\d+)(?:[,]\\s+)(\\d+)(?:\\s*[}])"

/**
 * @brief C/C++ formatter.
 */
class CFormatter
  : public Formatter
{
  FORMATTER_PREAMBLE(CFormatter, C_PRETTY)

  
public:
  
  bool read(QTextStream &stream,
            VersionInfo &info)
  {
    QString buffer = stream.readAll();
    bool    found  = false;
    
    if (buffer.isNull() || buffer.length() > 0) {
      /*
       * Start by preparing the buffer.
       */
      buffer.replace(QRegExp("\\s*\n\\s*"), " ");
      buffer.replace(QRegExp("="), " = ");
      buffer = buffer.simplified();
    
      /*
       * First, attempt to find the data using the regular expression
       * that matches the C/C++ structure definition.
       */
      {
        QRegExp re(SRE);
        int  pos = 0;
        bool ok  = false;
        
        while ((pos = re.indexIn(buffer, pos)) != -1)
        {  
          pos += re.matchedLength();
          
          info.setBaseYear(re.cap(1).toUInt(&ok, 10));
          info.setMajor(re.cap(2).toUInt(&ok, 10));
          info.setMinor(re.cap(3).toUInt(&ok, 10));
          info.setBuild(re.cap(4).toUInt(&ok, 10));
          info.setPatch(re.cap(5).toUInt(&ok, 10));
          
          if (ok) {
            found = true;
          }
        }
      }
      
      /*
       * If we didn't locate the version information via the above
       * regular expression, then try looking for a heap of `#define'
       * statements instead.
       */
      if (!found) {
        QRegExp re(DRE);
        int     cnt  = 0;
        int     pos  = 0;
        int     find = 0;
        bool    ok   = false;
        
        while ((pos = re.indexIn(buffer, pos)) != -1)
        {
          ++cnt;
          pos += re.matchedLength();
          
          if (re.cap(1).contains("BASE_YEAR")) {
            info.setBaseYear(re.cap(2).toUInt(&ok, 10));
            find++;
          } else if (re.cap(1).contains("MAJOR")) {
            info.setMajor(re.cap(2).toUInt(&ok, 10));
            find++;
          } else if (re.cap(1).contains("MINOR")) {
            info.setMinor(re.cap(2).toUInt(&ok, 10));
            find++;
          } else if (re.cap(1).contains("BUILD")) {
            info.setBuild(re.cap(2).toUInt(&ok, 10));
            find++;
          } else if (re.cap(1).contains("PATCH")) {
            info.setPatch(re.cap(2).toUInt(&ok, 10));
            find++;
          }
        }
        
        /*
         * Only mark it as found if all 5 defines can be found in the
         * file.
         */
        if (find == 5 && ok) {
          found = true;
        }
      }
      
      return found;
    }
    
    return false;
  }                             // bool read(...)
  
  bool write(QTextStream &stream,
             VersionInfo  info)
  {
    stream << "/*"                                                      << endl
           << " * ----------------------------------------------------" << endl
           << " * Automatically generated by VerBuild "
           << VERSION_STRING << "."                                     << endl
           << " * Do not edit by hand."                                 << endl
           << " * ----------------------------------------------------" << endl
           << " */"                                                     << endl
           << endl
           << "#pragma once"                                            << endl
           << endl
           << "#ifndef __VersionInfo_Header__"                          << endl
           << "#define __VersionInfo_Header__"                          << endl
           << endl;
    
    if (m_flags & OutputDoxygen) {
      stream << "/**"                                                   << endl
             << " * @file " << QFileInfo(m_fileName).fileName()         << endl
             << " * @author VerBuild " << VERSION_STRING                << endl
             << " * @brief Provides version information."               << endl
             << " */"                                                   << endl
             << endl;
    }
    
    if (m_flags & OutputBasic) {
      if (m_flags & OutputDoxygen) {
        stream << "/**"                                                 << endl
               << " * @def " << upcasePrefix() << "VERSION_MAJOR"       << endl
               << " * @brief Major version number."                     << endl
               << " *"                                                  << endl
               << " * @def " << upcasePrefix() << "VERSION_MINOR"       << endl
               << " * @brief Minor version number."                     << endl
               << " *"                                                  << endl
               << " * @def " << upcasePrefix() << "VERSION_BUILD"       << endl
               << " * @brief Build number."                             << endl
               << " *"                                                  << endl
               << " * @def " << upcasePrefix() << "VERSION_PATCH"       << endl
               << " * @brief Patch number."                             << endl
               << " *"                                                  << endl
               << " * @def " << upcasePrefix() << "VERSION_BASE_YEAR"   << endl
               << " * @brief The year the project was started."         << endl
               << " *"                                                  << endl
               << " * @def " << upcasePrefix() << "VERSION_DATE"        << endl
               << " * @brief The date this build was compiled."         << endl
               << " *"                                                  << endl
               << " * @def " << upcasePrefix() << "VERSION_TIME"        << endl
               << " * @brief The time this build was compiled."         << endl
               << " *"                                                  << endl
               << " * @def " << upcasePrefix() << "VERSION_STRING"      << endl
               << " * @brief String representation of the version."     << endl
               << " */"
               << endl;
      }
      
      stream << "#define " << upcasePrefix() << "VERSION_MAJOR      "
                << info.major()                                         << endl
             << "#define " << upcasePrefix() << "VERSION_MINOR      "
                << info.minor()                                         << endl
             << "#define " << upcasePrefix() << "VERSION_BUILD      "
                << info.build()                                         << endl
             << "#define " << upcasePrefix() << "VERSION_PATCH      "
                << info.patch()                                         << endl
             << endl
             << "#define " << upcasePrefix() << "VERSION_BASE_YEAR  "
                << info.baseYear()        << endl
             << "#define " << upcasePrefix() << "VERSION_DATE       "
                << "\"" << info.toDate().toString() << "\""             << endl
             << "#define " << upcasePrefix() << "VERSION_TIME       "
                << "\"" << QTime::currentTime().toString() << "\""      << endl
             << "#define " << upcasePrefix() << "VERSION_STRING     "
                << "\"" << info.toString() << "\""                      << endl
             << endl;
    }
    
    if (m_flags & OutputStruct) {
      if (m_flags & OutputDoxygen) {
        stream << "/**"                                                 << endl
               << " * @brief Version number structure."                 << endl
               << " *"                                                  << endl
               << " * @var baseYear"                                    << endl
               << " * @brief The year the project was started."         << endl
               << " *"                                                  << endl
               << " * @var major"                                       << endl
               << " * @brief Major version number"                      << endl
               << " *"                                                  << endl
               << " * @var minor"                                       << endl
               << " * @brief Minor version number."                     << endl
               << " *"                                                  << endl
               << " * @var patch"                                       << endl
               << " * @brief Patch number."                             << endl
               << " *"                                                  << endl
               << " * @var build"                                       << endl
               << " * @brief Build number."                             << endl
               << " */"
               << endl;
      }
          
      stream << "static struct " << prefix() << "VersionNumber_s {"     << endl
             << "  int baseYear;"                                       << endl
             << "  int major;"                                          << endl
             << "  int minor;"                                          << endl
             << "  int build;"                                          << endl
             << "  int patch;"                                          << endl
             << "} " << prefix() << "VersionNumber = {"                 << endl
             << "  " << info.baseYear() << ","                          << endl
             << "  " << info.major() << ","                             << endl
             << "  " << info.minor() << ","                             << endl
             << "  " << info.build() << ","                             << endl
             << "  " << info.patch()                                    << endl
             << "};"                                                    << endl
             << endl;
    }
      
    stream << "#endif // !__VersionInfo_Header__"
           << endl;
    
    return true;
  }                             // write(...)
  
};                              // class COutput

FORMATTER_REGISTER(CFormatter, "c", C_PRETTY)

#endif // !__CFormatter_hpp__

// CFormatter.hpp ends here
