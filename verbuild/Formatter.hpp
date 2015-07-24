//
// Formatter.hpp --- Output meta class.
//
// Copyright (c) 2013 Paul Ward <asmodai@gmail.com>
//
// Time-stamp: <Saturday Jun  1, 2013 22:14:10 asmodai>
// Revision:   58
//
// Author:     Paul Ward <asmodai@gmail.com>
// Maintainer: Paul Ward <asmodai@gmail.com>
// Created:    29 May 2013 04:13:11
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

#ifndef __Formatter_hpp__
#define __Formatter_hpp__

/**
 * @file Formatter.hpp
 * @author Paul Ward
 * @brief Source formatter meta class.
 */

#include <QtGlobal>
#include <QtCore/QString>
#include <QtCore/QStringList>
#include <QtCore/QFile>
#include <QtCore/QFileInfo>
#include <QtCore/QTextStream>
#include <QtCore/QRegExp>

#include "Enums.hpp"
#include "VersionInfo.hpp"
#include "version.hpp"

#include <map>
#include <cassert>
#include <vector>
#include <utility>
#include <algorithm>


/**
   @def FORMATTER_PREAMBLE
   @brief Convenience macro for generating output subclass constructor
          methods.
   @param TYPE The type of the formatter module.
   @param NAME The human-readable pretty name of the formatter module.
   @see FORMATTER_REGISTER
   
   This macro is designed to save having to type the same three
   constructor methods each time a new output class is added.
   
   Example:
   @code{.cpp}
   class FooFormatter
     : Formatter
   {
   public:
     FORMATTER_PREAMBLE(FooFormatter, "Foo Formatter")
     
     // ...
   }
   @endcode
 */
#define FORMATTER_PREAMBLE(TYPE, NAME)                  \
  private:                                              \
    static const std::size_t s_id;                      \
    static Formatter *create(void) { return new TYPE; } \
  public:                                               \
    TYPE()                                              \
      : Formatter()                                     \
    { m_formatterName = NAME; }                         \
    TYPE(const QString &file)                           \
      : Formatter(file)                                 \
    { m_formatterName = NAME; }                         \
    TYPE(const QString &file, const OutputFlags flags)  \
      : Formatter(file, flags)                          \
    { m_formatterName = NAME; }


/**
 * @brief Formatter meta class.
 *
 * This class is an abstraction that provides file writing
 * functionality.  What this means is that Formatter subclasses are
 * responsible for reading and writing version information to and
 * from files.
 */
class Formatter
{
protected:
  QString     m_formatterName;  //!< Formatter pretty name.
  QString     m_fileName;       //!< Version information file name.
  OutputFlags m_flags;          //!< Output flags.
  QString     m_outputPrefix;   //!< Prefix for "VERSION_" etc.
  
  
public:
  
  /**
   * @brief Default constructor method.
   *
   * Initialises the file name to a Null string and sets the output
   * flags to OutputAll.
   */
  Formatter()
  {
    m_formatterName = QString("<unknown>");
    m_fileName      = QString();
    m_flags         = OutputAll;
    m_outputPrefix  = QString();
  }
  
  /**
   * @brief Constructor method.
   * @param file The name of the file to read and write.
   *
   * Initialises the output flags to OutputAll.
   */
  Formatter(const QString &file)
    : m_fileName(file)
  {
    m_formatterName = QString("<unknown>");
    m_flags        = OutputAll;
    m_outputPrefix = QString();
  }
  
  /**
   * @brief Constructor method.
   * @param file The name of the file to read and write.
   * @param flags The output flags.
   */
  Formatter(const QString &file, const OutputFlags flags)
    : m_fileName(file),
      m_flags(flags)
  {
    m_formatterName = QString("<unknown>");
    m_outputPrefix  = QString();
  }
  
  /**
   * @brief Destructor method.
   */
  virtual ~Formatter()
  {}
  
  /**
   * @brief Return the human-readable name for this formatter.
   * @returns The human-readable name as a QString constant.
   */
  virtual QString const &formatterName(void) const
  {
    return m_formatterName;
  }
  
  /**
   * @brief Set the formatter file name to the file specified in
   *        @em name.
   * @param name The name of the file.
   */
  virtual void setFileName(const QString &name)
  {
    m_fileName = name;
  }
  
  /**
   * @brief Return the formatter file name.
   * @returns The file name in the form of a QString.
   */
  virtual QString const &fileName(void) const
  {
    return m_fileName;
  }
  
  /**
   * @brief Set the output flags to the flags specified in
   *        @em flags.
   * @param flags The output flags.
   */
  virtual void setFlags(const OutputFlags flags)
  {
    m_flags = flags;
  }
  
  /**
   * @brief Return the output flags.
   * @returns The output flags.
   */
  virtual OutputFlags const &flags(void) const
  {
    return m_flags;
  }
  
  /**
   * @brief Return the output prefix.
   * @returns A string value if a prefix has been set; otherwise an
   *          empty QString is returned.
   */
  virtual QString const prefix(void) const
  {
    if (!m_outputPrefix.isNull() && !m_outputPrefix.isEmpty()) {
      return m_outputPrefix +
        (m_outputPrefix.endsWith('_') ? "" : "_");
    }
    
    return QString();
  }
  
  /**
   * @brief Return the output prefix converted to upper case.
   * @returns A string value if a prefix has been set; otherwise an
   *          empty QString is returned.
   */
  virtual QString const upcasePrefix(void) const
  {
    return prefix().toUpper();
  }
  
  /**
   * @brief Set an output prefix to be written ahead of any symbols
   *        generated by the formatter.
   * @param value The prefix string value.
   */
  virtual void setPrefix(const QString &value)
  {
    m_outputPrefix = value;
  }
  
  /**
   * @brief Read the version information from a file.
   * @param info Pointer to the version information object to store
   *             the data in.
   * @returns @c true if the read was successful; otherwise @c false
   *          is returned.
   */
  virtual bool read(VersionInfo &info)
  {
    if (!m_fileName.isNull() && !m_fileName.isEmpty()) {
      QFile file(m_fileName);
      
      file.open(QIODevice::ReadOnly | QIODevice::Text);
      if (file.isOpen()) {
        QTextStream stream(&file);
        
        read(stream, info);
        file.close();
        
        return true;
      }
    }      
    
    return false;
  }
  
  /**
   * @brief Read the version information from a file.
   * @param stream The text stream to read the information from.
   * @param info Pointer to the version information object to store
   *             the data in.
   * @returns @c true if the read was successful; otherwise @c false
   *          is returned.
   */
  virtual bool read(QTextStream &stream, VersionInfo &info) = 0;
  
  /**
   * @brief Write the version information to a file.
   * @param info The version information to write to file.
   * @returns @c true if the write was successful; otherwise @c false
   *          is returned.
   */
  virtual bool write(VersionInfo info)
  {
    if (!m_fileName.isNull() && !m_fileName.isEmpty()) {
      QFile file(m_fileName);
      
      file.open(QIODevice::WriteOnly | QIODevice::Text);
      if (file.isOpen()) {
        QTextStream stream(&file);
        
        write(stream, info);
        file.close();
        
        return true;
      }
    } else {
      QTextStream stream(stdout);
      
      write(stream, info);
    }
    
    return false;
  }
  
  /**
   * @brief Write the version information to a file.
   * @param stream The text stream to output the information to.
   * @param flags The output flags.
   * @param info The version information to write to file.
   * @returns @c true if the write was successful; otherwise @c false
   *          is returned.
   * @overload
   */
  virtual bool write(QTextStream       &stream,
                     const OutputFlags  flags,
                     VersionInfo        info)
  {
    m_flags = flags;
    
    return write(stream, info);
  }
  
  /**
   * @brief Write the version information to a file.
   * @param stream The text stream to output the information to.
   * @param info The version information to write to file.
   * @returns @c true if the write was successful; otherwise @c false
   *          is returned.
   * @overload
   */
  virtual bool write(QTextStream &stream,
                     VersionInfo  info) = 0;
  
};                              // class Output

/**
 * @brief Formatter creation function.
 */
typedef Formatter *(*FormatterCreateFn)(void);

/**
 * @brief Map of formatter names and creation functions.
 */
typedef std::map<std::string, FormatterCreateFn> FormatterFnMap;
typedef std::map<std::string, std::string> FormatterNameMap;

/**
 * @brief Formatter class factory.
 */
class FormatterFactory
{
private:
  /**
   * @var s_mapFn
   * @brief Map of names and creation functions.
   *
   * @var s_mapNames
   * @brief Map of names and pretty names.
   *
   * @var s_id
   * @brief ID of output class within list. (internal)
   */
  static FormatterFnMap   s_mapFn;
  static FormatterNameMap s_mapNames;
  static std::size_t      s_id;
  
  
public:
  /**
   * @brief Register a formatter class creation function.
   * @param creator The object creation method.
   * @param name The name of the formatting module.
   * @param pretty The pretty name of the formatting module.
   * @returns The size of the name/class map after the new output
   *          class has been registered.
   * @note The return value is largely meaningless.
   * @note The output formatting module name is @em not the same as
   *       the human-readable name.
   */
  static std::size_t registerFormatter(FormatterCreateFn creator,
                                       std::string       name,
                                       std::string       pretty)
  {
    assert(creator);
    assert(name.length() > 0);
    assert(pretty.length() > 0);
    
    std::transform(name.begin(), name.end(), name.begin(), ::tolower);

    s_mapFn[name]    = creator;
    s_mapNames[name] = pretty;
    
    return s_mapFn.size();
  }
  
  /**
   * @brief Create a new instance of the output formatter specified
   *        with @em name.
   * @param name The output formatter name.
   * @returns A new instance of a formatter module.
   * @note The output formatting module name is @em not the same as
   *       the human-readable name.
   */
  static Formatter *create(std::string name)
  {
    assert(name.length() > 0);
    
    std::transform(name.begin(), name.end(), name.begin(), ::tolower);

    return (s_mapFn[name])();
  }
  
  /**
   * @brief Return the size of the function map.
   * @returns Returns the size of the formatter function map.
   */
  static FormatterFnMap::size_type size(void)
  {
    return s_mapFn.size();
  }
  
  /**
   * @brief Return an iterator pointing to the start of the function
   *        map.
   * @returns Returns an iterator.
   */
  static FormatterFnMap::iterator begin(void)
  {
    return s_mapFn.begin();
  }
  
  /**
   * @brief Return an integer pointing to the end of the function map.
   * @returns Returns an iterator.
   */
  static FormatterFnMap::iterator end(void)
  {
    return s_mapFn.end();
  }

  /**
   * @brief Return the corresponding string value from the map of
   *        pretty names given a valid key.
   * @param formatter The formatter name.
   * @returns A string containing either the pretty name of the
   *          formatter, or nothing.
   */
  static std::string nameForFormatter(std::string formatter)
  {
    return s_mapNames[formatter];
  }
  
};                              // class FormatterFactory

#ifndef _EXTERNAL_
/* Initial value. */
FormatterFnMap FormatterFactory::s_mapFn      = FormatterFnMap();
FormatterNameMap FormatterFactory::s_mapNames = FormatterNameMap();
#endif

/**
   @def FORMATTER_REGISTER
   @brief Register an output formatter module.
   @param TYPE The type of the formatter module.
   @param NAME The name of the formatter module.
   @param PRETTY The pretty name of the formatter module.
   @note The name given here is not the same as the human-readable
         name used by @c FORMATTER_PREAMBLE, so please be aware of this.
   @see FORMATTER_PREAMBLE
   
   Registers a new formatter module at compile-time.
   
   Example:
   @code{.cpp}
   class FooFormatter
     : Formatter
   {
     // ...
   }
   FORMATTER_REGISTER(FooFormatter, "Foo")
   @endcode
 */
#define FORMATTER_REGISTER(TYPE, NAME, PRETTY)          \
  const std::size_t TYPE::s_id =                        \
    FormatterFactory::registerFormatter(&create, NAME, PRETTY);

#endif // !__Formatter_hpp__

// Formatter.hpp ends here
