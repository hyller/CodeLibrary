//
// VersionInfo.hpp --- Version information class.
//
// Copyright (c) 2013 Paul Ward <asmodai@gmail.com>
//
// Time-stamp: <Saturday Jun  1, 2013 10:57:34 asmodai>
// Revision:   37
//
// Author:     Paul Ward <asmodai@gmail.com>
// Maintainer: Paul Ward <asmodai@gmail.com>
// Created:    29 May 2013 02:13:55
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

#ifndef __VersionInfo_hpp__
#define __VersionInfo_hpp__

/**
 * @file VersionInfo.hpp
 * @author Paul Ward
 * @brief Version information class.
 */

#include <QtGlobal>
#include <QtCore/QDate>
#include <QtCore/QString>
#include <QtCore/QRegExp>

#include "Enums.hpp"
#include <limits.h>

#include <iostream>


/**
   @brief Version information class.
   
   The version number used by this class contains four components:
   
   Component | Description
   :--------:|-------------------
   Major     | The major version number of a project.
   Minor     | The minor version number of a project.
   Build     | The build number of a project, see below.
   Patch     | The patch or the service pack.
   
   Of special interest is the build number, which can be generated and
   incremented using a few methods:
   
   ###Simple incrementation###
   This is the most simple method whereby the build number is
   incremented sequentially, i.e. a build number of 1 increments to 2,
   or a build number of 41 increments to 42.
   
   ###Month offset incrementation###
   Otherwise known as the @em Microsoft @em Office method.  The build
   number is composed using the following method:
   
   1. Set a 'base year' for the project.
   2. Compute the difference in months between January 1st of the base
      year and the current month, this becomes the first group of
      digits.
   3. Take the day number of the current month, this becomes the
      second group of digits.
   
   For example, let us imagine we have a project started in 2003.
   This project goes along quite nicely, and we're compiling it from
   source on October 17th, 2005, 34 months after the start year.  The
   build number would be @b 3417.  Or, 17th day of the 34th month
   after January 2003.

   ###Year offset incrementation###
   Otherwise known as the @em Microsoft @em Visual @em C++
   @em compiler method. The build number is composed using the
   following method:
   
   1. Set a 'base year' for the project.
   2. Compute the difference in years between the current year and the
      base year, this becomes the first group of digits.
   3. Add the two-digit month number for the current month.
   4. Add the two-digit day number for the current month.
   
   For example, let us imagine we have a project started in 2005.
   This project goes along quite nicely, and we're compiling it from
   source on September 4th, 2007.  2 years after the start year.  The
   build number would be @b 20904.
   
   ###Date incrementation###
   The second-simplest method, otherwise known as @em ISO @em 8601.
   The build number is just the date encoded as yyyymmdd.
   
 */
class VersionInfo
{
private:
  unsigned int m_major;         //!< Major version number.
  unsigned int m_minor;         //!< Minor version number.
  unsigned int m_build;         //!< Build number.
  unsigned int m_patch;         //!< Patch or service pack number.
  unsigned int m_baseYear;      //!< Base year for the project.
  BuildTypes   m_buildType;     //!< Incrementation type for build number.
  bool         m_overflow;      //!< Overflow checking enabled?
  
  
public:
  
  /**
   * @brief Constructor method.
   */
  VersionInfo()
    : m_major(0),
      m_minor(0),
      m_build(0),
      m_patch(0),
      m_baseYear(1970),
      m_buildType(BuildSimple),
      m_overflow(false)
  {}
  
  /**
   * @brief Constructor method.
   * @param major Major version number.
   * @param minor Minor version number.
   * @param build Build number.
   * @param patch Patch or service pack number.
   * @param baseYear Year that the project was started.
   * @param type Incrementation type.
   * @see BuildType
   */
  VersionInfo(const unsigned int major,
              const unsigned int minor,
              const unsigned int build    = 0,
              const unsigned int patch    = 0, 
              const unsigned int baseYear = 1970,
              const BuildTypes   type     = BuildSimple)
    : m_major(major),
      m_minor(minor),
      m_build(build),
      m_patch(patch),
      m_baseYear(baseYear),
      m_buildType(type),
      m_overflow(false)
  {}
  
  /**
   * @brief Return the major version number.
   * @returns The major version number.
   */
  unsigned int const &major(void) const
  {
    return m_major;
  }
  
  /**
   * @brief Set the major version number.
   * @param value The value to set.
   */
  void setMajor(const unsigned int value)
  {
    m_major = value;
  }
  
  /**
   * @brief Return the minor version number.
   * @returns The minor version number.
   */
  unsigned int const &minor(void) const
  {
    return m_minor;
  }
  
  /**
   * @brief Set the minor version number.
   * @param value The value to set.
   */
  void setMinor(const unsigned int value)
  {
    m_minor = value;
  }
  
  /**
   * @brief Return the build number.
   * @returns The build number.
   */
  unsigned int const &build(void) const
  {
    return m_build;
  }
  
  /**
   * @brief Set the build number.
   * @param value The value to set.
   */
  void setBuild(const unsigned int value)
  {
    m_build = value;
  }
  
  /**
   * @brief Return the patch or service pack number.
   * @returns The patch or service pack number.
   */
  unsigned int const &patch(void) const
  {
    return m_patch;
  }
  
  /**
   * @brief Set the patch or service pack number.
   * @param value The value to set.
   */
  void setPatch(const unsigned int value)
  {
    m_patch = value;
  }
  
  /**
   * @brief Return the base year of the project.
   * @returns The base year of the project.
   */
  unsigned int const &baseYear(void) const
  {
    return m_baseYear;
  }
  
  /**
   * @brief Set the base year of the project.
   * @param value The value to set.
   */
  void setBaseYear(const unsigned int value)
  {
    m_baseYear = value;
  }
  
  /**
   * @brief Return the build number incrementation type.
   * @returns The incrementation type.
   */
  BuildTypes const &buildType(void) const
  {
    return m_buildType;
  }
  
  /**
   * @brief Set the build number incrementation type.
   * @param value The value to set.
   */
  void setBuildType(const BuildTypes value)
  {
    m_buildType = value;
  }
  
  /**
   * @brief Increment the version number.
   * @param what A bitfield defining which number(s) should be
   *             incremented.
   * @see Increment
   */
  void increment(const Increments what = IncrementBuild)
  {
    if (what & IncrementMajor) {
      m_major = incr(m_major);
    }
    
    if (what & IncrementMinor) {
      m_minor = incr(m_minor);
    }
    
    if (what & IncrementBuild) {
      incrementBuild();
    }
    
    if (what & IncrementPatch) {
      m_patch = incr(m_patch);
    }
  }
  
  /**
   * @brief Convert the version number to a string.
   * @returns A QString containing the version number.
   */
  QString toString(void) const
  {
    QString ret = QString();
    QTextStream(&ret) << m_major << "."
                      << m_minor << "."
                      << m_build << "."
                      << m_patch;
    
    return ret;
  }
  
  /**
   * @brief Return the build date this version number corresponds to.
   * @returns If the incrementation type encodes date information into
   *          the build number, then a QDate containing that date will
   *          be returned; otherwise an empty QDate is returned.
   */
  QDate toDate(void) const
  {
    QDate date = QDate();
    
    if (m_build > 0 && m_baseYear > 0) {
      switch (m_buildType) {
        case BuildByDate:
          {
            QString      buf;
            QRegExp      re("(\\d{4,4})(\\d{2,2})(\\d{2,2})");
            unsigned int dd = 0;
            unsigned int mm = 0;
            unsigned int yy = 0;
            bool         ok = true;
            
            buf.setNum(m_build);

            if (re.indexIn(buf) != -1) {
              yy = re.cap(1).toUInt(&ok, 10);
              mm = re.cap(2).toUInt(&ok, 10);
              dd = re.cap(3).toUInt(&ok, 10);
            } else {
              ok = false;
            }
            
            if (ok) {
              date.setDate(yy, mm, dd);
            }
          }
          break;
          
        case BuildByYears:
          {
            QString      buf;
            int          pos = 0;
            unsigned int dd  = 0;
            unsigned int mm  = 0;
            unsigned int yy  = 0;
            bool         ok  = true;

            // Set the build number into the buffer.
            buf.setNum(m_build);

            // Are we in the same year of the project start date?
            if (buf.length() > 3) {
              // Nope, carry on.
              QRegExp re("(\\d*)(\\d{2,2})(\\d{2,2})");

              if (re.indexIn(buf) != -1) {
                yy = re.cap(1).toUInt(&ok, 10);
                mm = re.cap(2).toUInt(&ok, 10);
                dd = re.cap(3).toUInt(&ok, 10);
              } else {
                ok = false;
              }
            } else {
              // Yep, so use a different regexp.
              QRegExp re("(\\d{1,2})(\\d{2,2})");

              if (re.indexIn(buf, pos) != -1) {
                yy = 0;
                mm = re.cap(1).toUInt(&ok, 10);
                dd = re.cap(2).toUInt(&ok, 10);
              } else {
                ok = false;
              }
            }
            
            if (ok) {
              date.setDate(m_baseYear + yy, mm, dd);
            }
          }
          break;
          
        case BuildByMonths:
          date.setDate(m_baseYear,
                       1,
                       (unsigned int)m_build % 100);
          date = date.addMonths((m_build / 100) - 1);
          break;
      }
    }
    
    return date;
  }                             // QDate toDate() const

  
  /**
   * @brief Equality test.
   * @param other The other object to compare with.
   * @returns @c true if both objects are equal; otherwise @c false is
   *          returned.
   */
  bool operator == (const VersionInfo &other)
  {
    return (m_major == other.m_major)
      && (m_minor == other.m_minor)
      && (m_build == other.m_build)
      && (m_patch == other.m_patch);
  }
  
  /**
   * @brief Inequality test.
   * @param other The other object to compare with.
   * @returns @c if both objects are inequal; otherwise @c false is
   *          returned.
   */
  bool operator != (const VersionInfo &other)
  {
    return (m_major != other.m_major)
      || (m_minor != other.m_minor)
      || (m_build != other.m_build)
      || (m_patch != other.m_patch);
  }
  
  
private:
  
  unsigned int incr(const unsigned int lhs) const
  {
    if (m_overflow) {
      if ((UINT_MAX - 1) < lhs) {
        return UINT_MAX;
      }
    }
     
    return lhs + 1;
  }
  
  unsigned int add(const unsigned int lhs,
                   const unsigned int rhs) const
  {
    if (m_overflow) {
      if ((UINT_MAX - rhs) < lhs) {
        return UINT_MAX;
      }
    }
    
    return lhs + rhs;
  }
  
  /**
   * @brief Increments the build number.
   * @see BuildType
   *
   * Does the actual work when it comes to incrementing the build number.
   */
  void incrementBuild()
  {
    switch (m_buildType) {
      case BuildSimple:         // Simple incrementing.
        m_build++;
        break;
        
      case BuildByMonths:       // Increment by months.
        if (m_baseYear > 0) {
          m_build = add((QDate::currentDate().year() - m_baseYear) * 12,
                        QDate::currentDate().month());
          m_build = add(m_build * 100, QDate::currentDate().day());
        }
        break;
        
      case BuildByYears:  // Increment by years.
        {
          QString str = QString();
          bool    ok;
          
          str.sprintf("%d%02d%02d",
                      QDate::currentDate().year() - m_baseYear,
                      QDate::currentDate().month(),
                      QDate::currentDate().day());
          
          m_build = str.toUInt(&ok, 10);
          
          if (!ok) {
            m_build = 0;
          }
        }
        break;
        
      case BuildByDate:   // Increment by date.
        {
          bool ok;
          
          m_build = QDate::currentDate().toString("yyyyMMdd").toUInt(&ok, 10);
          
          if (!ok) {
            m_build = 0;
          }
        }
        break;
    }
  }                             // void incrementBuild()
  
};                              // class VersionInfo

#endif // !__VersionInfo_hpp__

// VersionInfo.hpp ends here
