verbuild
========

Version number auto-incrementing and build numbering tool.


This tool maintains version numbers with 4 components:

   Component | Description
   ----------|-------------------
   Major     | The major version number of a project.
   Minor     | The minor version number of a project.
   Build     | The build number of a project, see below.
   Patch     | The patch or the service pack
   
Of special interest is the build number, which can be generated and
incremented using a few methods: 
   

Simple incrementation
---------------------
This is the most simple method whereby the build number is incremented
sequentially, i.e. a build number of 1 increments to 2, or a build number of
41 increments to 42. 
   

Month offset incrementation
---------------------------
Otherwise known as the Microsoft Office method.  The build number is composed
using the following method: 
   
   1. Set a 'base year' for the project.
   2. Compute the difference in months between January 1st of the base year
      and the current month, this becomes the first group of digits. 
   3. Take the day number of the current month, this becomes the second group
      of digits.
   
For example, let us imagine we have a project started in 2003. This project
goes along quite nicely, and we're compiling it from source on October 17th,
2005, 34 months after the start year.  The build number would be 3417.  Or,
17th day of the 34th month after January 2003.


Year offset incrementation
--------------------------
Otherwise known as the Microsoft Visual C++ compiler method. The build number
is composed using the following method:
   
   1. Set a 'base year' for the project.
   2. Compute the difference in years between the current year and the base
      year, this becomes the first group of digits.
   3. Add the two-digit month number for the current month.
   4. Add the two-digit day number for the current month.
   
For example, let us imagine we have a project started in 2005. This project
goes along quite nicely, and we're compiling it from source on September 4th,
2007.  2 years after the start year.  The build number would be 20904.


Date incrementation
-------------------
The second-simplest method, otherwise known as ISO 8601. The build number is
just the date encoded as yyyymmdd.


Output
------
The verbuild tool can, as of right now, only handle output to C/C++ files, but
even then it has two ways of outputting information -- #define statements and
a structure.

Hopefully more output formats will be added in the near future.


Input
-----
The verbuild tool can parse existing headers for version information.  To see
what is required, please take a look at the CFormatting.hpp file.


Flags and options
-----------------
Usage:

    verbuild  [-c] [-f <x.x.x.x>] [-g <basic|struct|doxygen|all>] ...  [-i
              <simple|date|months|years>] [-o <string>] [-p <string>] [-s]
               -t <c> [-v] [-y <[1970...2013]>] [--] [--version] [-h]



Where:

    -c,  --create
      Create the output file if it does not exist.
 
    -f <x.x.x.x>,  --format <x.x.x.x>
      Version number format string.
      
    -g <basic|struct|doxygen|all>,  --groups <basic|struct|doxygen|all>
       (accepted multiple times)
      Output groups generated.
    
    -i <simple|date|months|years>,  --increment <simple|date|months|years>
      Type of increment used.
    
    -o <string>,  --output <string>
      File containing version information.
    
    -p <string>,  --prefix <string>
      String to prepend to symbols created by the formatter.
    
    -s,  --overflow
      Perform overflow checking and shifting.
    
    -t <c>,  --formatter <c>
      (required)  Output formatter type: c = C/C++
    
    -v,  --verbose
      Verbose output.
    
    -y <[1970...2013]>,  --base-year <[1970...2013]>
      The year the project was started.
    
    --,  --ignore_rest
      Ignores the rest of the labeled arguments following this flag.
    
    --version
      Displays version information and exits.
    
    -h,  --help
      Displays usage information and exits.



Format specifier
----------------
The format required for a version number is 'x.x.x.x', where x can be one of
the following:
   
   Format | Description
   -------|--------------------------------
   *      | Number component is left as-is.
   +      | Number component is incremented.
   [0-9]+ | Number component is a constant.
   
As an example, if we have a format string of `10.*.+.*`, then the version
number will contain the following components:
   
   Component | Description
   ----------|---------------------------
   10        | The major version will always have the value 10.
   *         | The minor number will be left as-is.
   +         | The build number will be incremented.
   *         | The patch number will be left as-is. 
   
Therefore, if the version number is read in from a header as `5.5.8.1`, then
after processing, the format will result in a new version number of
`10.5.9.1`.


Examples
--------

The most basic of invocations is:

    $ verbuild -t c -g basic

which results in the following output to stdout:

    /* ----------------------------------------------------
     * Automatically generated by VerBuild 1.0.601.2.
     * Do not edit by hand.
     * ----------------------------------------------------
     */

    #ifndef __VersionInfo_Header__
    #define __VersionInfo_Header__
    
    #define VERSION_MAJOR      0
    #define VERSION_MINOR      0
    #define VERSION_BUILD      1
    #define VERSION_PATCH      0
    
    #define VERSION_BASE_YEAR  1970
    #define VERSION_DATE       ""
    #define VERSION_TIME       "12:11:19"
    #define VERSION_STRING     "0.0.1.0"
    
    #endif // !__VersionInfo_Header__


A more advanced example would be:

    $ verbuild -t c -y 2010 -i years -f 10.*.+.* -g struct

which yields:

    /* ----------------------------------------------------
     * Automatically generated by VerBuild 1.0.601.2.
     * Do not edit by hand.
     * ----------------------------------------------------
     */
    
    #ifndef __VersionInfo_Header__
    #define __VersionInfo_Header__
    
    static struct VersionNumber_s {
      int baseYear;
      int major;
      int minor;
      int build;
      int patch;
    } VersionNumber = {
      2010,
      10,
      0,
      30601,
      0
    };
    
    #endif // !__VersionInfo_Header__

To deal with a file, one can use:

    $ verbuild -t c -y 2010 -i months -f 13.04.*.1 -g basic -g doxygen -o test.h -c

The resulting file will look like this:

    /* ----------------------------------------------------
     * Automatically generated by VerBuild 1.0.601.2.
     * Do not edit by hand.
     * ----------------------------------------------------
     */
    
    #ifndef __VersionInfo_Header__
    #define __VersionInfo_Header__
    
    /**
     * @file test.h
     * @author VarBuild 1.0.601.2
     * @brief Provides version information.
     */
    
    /**
     * @def VERSION_MAJOR
     * @brief Major version number.
     *
     * @def VERSION_MINOR
     * @brief Minor version number.
     *
     * @def VERSION_BUILD
     * @brief Build number.
     *
     * @def VERSION_PATCH
     * @brief Patch number.
     *
     * @def VERSION_BASE_YEAR
     * @brief The year the project was started.
     *
     * @def VERSION_DATE
     * @brief The date this build was compiled.
     *
     * @def VERSION_TIME
     * @brief The time this build was compiled.
     *
     * @def VERSION_STRING
     * @brief String representation of the version.
     */
    #define VERSION_MAJOR      13
    #define VERSION_MINOR      4
    #define VERSION_BUILD      0
    #define VERSION_PATCH      1
    
    #define VERSION_BASE_YEAR  2010
    #define VERSION_DATE       ""
    #define VERSION_TIME       "12:22:17"
    #define VERSION_STRING     "13.4.0.1"
    
    #endif // !__VersionInfo_Header__

 You can also prefix the symbols generated thusly:
 
     verbuild -t c -g basic -p hello
     
 which generates output similar to:
 
    /*
     * ----------------------------------------------------
     * Automatically generated by VerBuild 1.1.601.0.
     * Do not edit by hand.
     * ----------------------------------------------------
     */
    
    #pragma once
    
    #ifndef __VersionInfo_Header__
    #define __VersionInfo_Header__
    
    #define HELLO_VERSION_MAJOR      0
    #define HELLO_VERSION_MINOR      0
    #define HELLO_VERSION_BUILD      1
    #define HELLO_VERSION_PATCH      0
    
    #define HELLO_VERSION_BASE_YEAR  1970
    #define HELLO_VERSION_DATE       ""
    #define HELLO_VERSION_TIME       "22:50:59"
    #define HELLO_VERSION_STRING     "0.0.1.0"
    
    #endif // !__VersionInfo_Header__

For an example on using verbuild with Windows resource files, see
resource.rc.

