//
// main.cpp --- Version numbering.
//
// Copyright (c) 2013 Paul Ward <asmodai@gmail.com>
//
// Time-stamp: <Saturday Jun  1, 2013 22:41:27 asmodai>
// Revision:   9
//
// Author:     Paul Ward <asmodai@gmail.com>
// Maintainer: Paul Ward <asmodai@gmail.com>
// Created:    01 Jun 2013 09:12:33
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
//
// }}}

/**
 * @file main.cpp
 * @author Paul Ward
 * @brief Main function.
 */

#include <QDebug>

#include <QtCore/QString>
#include <QtCore/QTextStream>

#include "Enums.hpp"
#include "VersionInfo.hpp"
#include "Formatter.hpp"
#include "CFormatter.hpp"
#include "Settings.hpp"

#include <cstdlib> // for EXIT_SUCCESS

/**
 * @brief Main routine.
 * @param argc Count of arguments.
 * @param argv Array of arguments.
 * @returns @c EXIT_SUCCESS, always.  For now.
 */
int
main(int argc, char **argv)
{
  Settings     settings(argc, argv);
  VersionInfo  info = VersionInfo();
  Formatter   *fmtr = NULL;
  
  if (settings.verbose()) {
    settings.dump();
  }
  
  // Do we have a valid formatter?
  if (settings.formatter().isEmpty() ||
      settings.formatter().isNull())
  {
    qFatal("No output formatter was specified.");
  }
  
  // Attempt to create the formatter instance.
  fmtr = FormatterFactory::create(settings.formatter().toStdString());
  
  // Check we have a valid formatter.
  if (fmtr == NULL) {
    qFatal("Could not instantiate chosen formatter.  Aborting...");
  }
  
  // Were we given a file to work on?
  if (!settings.useStdOut()) {
    QFile file(settings.filePath());
    
    // Check it exists.
    if (!file.exists() && !settings.createFile()) {
      qFatal("The specified file does not exist.  Aborting...");
    }
    
    // It exists, so let's use it.
    fmtr->setFileName(settings.filePath());
  }
  
  // Configure any prefix that might be needed.
  fmtr->setPrefix(settings.outputPrefix());
  
  // If there is no filename set, nothing will happen here.
  fmtr->read(info);
  
  // Print out the version read.
  if (settings.verbose()) {
    QTextStream out(stdout);
    
    out << "Parsed version: " << info.toString() << endl;
  }
  
  // Configure what we want to output.
  fmtr->setFlags(settings.outputFlags());
  
  // Configure the build type.
  info.setBuildType(settings.incrementType());
  
  // Override the base year, if required.
  if (settings.baseYear() > 0) {
    info.setBaseYear(settings.baseYear());
  }
  
  // Perform the increment.
  info.increment(settings.incrementFields());

  // Force initial version numbers.
  for (int i = 0; i < 4; ++i) {
    InitialValues v = settings.initialVersion()[i];

    if (v.use) {
      switch (i) {
        case 0: info.setMajor(v.value); break;
        case 1: info.setMinor(v.value); break;
        case 2: info.setBuild(v.value); break;
        case 3: info.setPatch(v.value); break;
      }
    }
  }
  
  // Print out the new version.
  if (settings.verbose()) {
    QTextStream out(stdout);
    
    out << "New version:    " << info.toString() << endl;
  }
  
  // Write out the new version.
  fmtr->write(info);
  
  // We're done.
  return EXIT_SUCCESS;
}

// main.cpp ends here
