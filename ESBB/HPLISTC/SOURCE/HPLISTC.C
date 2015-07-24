/*$TITLE=Program to list C source files on an HP Laserjet printer*/
/*
*********************************************************************************************************
*                                              HPLISTC
*
*                     Program to list C source files on an HP Laserjet Printer
*
*
*
* Filename     : HPLISTC.C
* Programmer(s): Jean J. Labrosse
*********************************************************************************************************
*
*
* Program use :
*
*        HPLISTC filename.ext [L | P] [>destination]
*
*        where :
*
*             filename.ext        Is the name of the file to list (with extension)
*             [L]                 Indicates that the printer will print in LANDSCAPE mode
*             [P]                 Indicates that the printer will print in PORTRAIT  mode (default)
*             [>destination]      Is the destination of the listed file, it can be:
*                                      >PRN        for the printer
*                                      >file.ext   for redirecting it to a file
*
* Note: This program is compiled using the Borland International C++ compiler Version 3.0
*********************************************************************************************************
*/

/*
*********************************************************************************************************
*                                              INCLUDES
*********************************************************************************************************
*/

#include <STDIO.H>
#include <STRING.H>
#include <DOS.H>

/*$PAGE*/
/*
*********************************************************************************************************
*                                          LOCAL CONSTANTS
*********************************************************************************************************
*/
#define  PRINTER_FORM_FEED        0x0C
                                                           /* compressed mode, 10 pts BOLD             */
#define  PRINTER_COMPRESSED_MODE  "\x01B(10U\x01B(s0P\x01B(s16.6H\x01B&k2S\x01B(s3B"
#define  PRINTER_LANDSCAPE        "\x01B&l1O"                                  /* LANDSCAPE  mode.     */
#define  PRINTER_NORMAL_MODE      "\x01B&l0O\033E"                             /* normal     mode.     */
#define  PRINTER_PAGE_LENGTH      "\x01B&l2E\x01B&l7.6C\x01B&l66F"             /* 66 lines/page.       */
#define  NUL                      0x00
#define  NULLPTR                  (char *)0

#define  PORTRAIT                 0
#define  LANDSCAPE                1

#define  TRUE                     1
#define  FALSE                    0


/*
*********************************************************************************************************
*                                         TYPE DECLARATIONS
*********************************************************************************************************
*/

typedef  unsigned char BOOLEAN;


typedef struct cmd {                             /* Special comment COMMANDS structure                 */
    char  *CmdName;                              /* Name of COMMAND                                    */
    void (*CmdFnct)(char *s);                    /* Function to execute when COMMAND is found          */
} CMD;


/*
*********************************************************************************************************
*                                       FUNCTION PROTOTYPES
*********************************************************************************************************
*/

        void    main(int argc, char *argv[]);
static  void    ListcInit(void);
static  BOOLEAN ListcChkCmd(char *s);
static  void    ListcNewPage(char *s);
static  void    ListcChangeTitle(char *s);
static  void    ListcHdr(void);
static  void    ListcGetDate(char *s);
static  void    ListcGetTime(char *s);

/*$PAGE*/
/*
*********************************************************************************************************
*                                          GLOBAL VARIABLES
*********************************************************************************************************
*/

static  char      ListcInStr[256];               /* Input  String                                      */
static  char      ListcDate[30];                 /* Current Date                                       */
static  char      ListcTime[30];                 /* Current Time                                       */
static  char      ListcFileName[100];            /* File Name                                          */
static  int       ListcLineN;                    /* Line counter                                       */
static  int       ListcPageN;                    /* Page counter                                       */
static  char      ListcTitle[150];               /* Page TITLE                                         */
static  FILE     *ListcSrcFile;                  /* File pointer (Input file)                          */
static  int       ListcMode;

/*
*********************************************************************************************************
*                                              TABLES
*********************************************************************************************************
*/

static  char     *ListcMonths[] = {              /* Table of MONTHs                                    */
    "",
    "January",
    "February",
    "March",
    "April",
    "May",
    "June",
    "July",
    "August",
    "September",
    "October",
    "November",
    "December"
};


static  CMD  ListcCmdTable[] = {                 /* Table of comment COMMANDS                          */
    {"page",   ListcNewPage},                    /* PAGE break command                                 */
    {"PAGE",   ListcNewPage},
    {"title",  ListcChangeTitle},                /* TITLE command                                      */
    {"TITLE",  ListcChangeTitle},
    {"",       (void (*)())0}
};

/*$PAGE*/
/*
*********************************************************************************************************
*                                          LISTC ENTRY POINT
*********************************************************************************************************
*/

void main(int argc, char *argv[])
{
    if (argc < 2 || argc > 3) {                                      /* Valid number of arguments ?    */
        fprintf(stdout, "\n\n");
        fprintf(stdout, "Name of file to print missing, use:\n\n");
        fprintf(stdout, "     HPLISTC filename.ext [L | l | P | p] [>destination]\n\n\n");
        fprintf(stdout, "     where:\n");
        fprintf(stdout, "         filename.ext is the name of the file to print\n");
        fprintf(stdout, "         L | l        indicates to put the printer in LANDSCAPE mode\n");
        fprintf(stdout, "         P | p        indicates to put the printer in PORTRAIT  mode (Dflt)\n");
        fprintf(stdout, "         destination  is the redirected destination of the file\n");
        fprintf(stdout, "                      >PRN      to redirect the file to the printer\n");
        fprintf(stdout, "                      >file.ext to redirect to a file\n");
        return;
    }
    ListcMode = PORTRAIT;                                            /* Default to PORTRAIT mode       */
    if (argc > 2) {                                                  /* See if mode is specified       */
        if ((strcmp(argv[2], "L") == 0) || (strcmp(argv[2], "l") == 0))
            ListcMode = LANDSCAPE;                                   /* Force to LANDSCAPE mode        */
    }
    ListcInit();                                                     /* Perform initializations        */
    strcpy(ListcFileName, argv[1]);                                  /* Get file name                  */
    ListcSrcFile = fopen(ListcFileName, "r");                        /* Open file to list              */
    if (ListcSrcFile == NULL) {                                      /* Make sure that file got opened */
        fprintf(stdout, "Cannot open %s.\n", ListcFileName);         /* Display error message          */
        return;
    }
    ListcHdr();                                                      /* Print page header              */
    while (fgets(ListcInStr, 250, ListcSrcFile) != NULL) {           /* Print code                     */
        if (ListcChkCmd(ListcInStr) == FALSE) {                      /* See if input line is a command */
            fprintf(stdout, "%04d  %s", ListcLineN, ListcInStr);
        }
        ListcLineN++;
    }
    fclose(ListcSrcFile);                                            /* Close input file               */
    fprintf(stdout, "%c", PRINTER_FORM_FEED);
    fprintf(stdout, "%s", PRINTER_NORMAL_MODE);                      /* Set printer to normal mode     */
}

/*$PAGE*/
/*
*********************************************************************************************************
*                                          INITIALIZE LISTC
*********************************************************************************************************
*/

static void ListcInit(void)
{
    ListcLineN = 1;
    ListcPageN = 1;
    strcpy(ListcTitle, "");                                /* No TITLE when we start                   */
    ListcGetDate(ListcDate);                               /* Get the current date 'Month day, year'   */
    ListcGetTime(ListcTime);                               /* Get the current time 'HH:MM:SS'          */
    fprintf(stdout, "%s", PRINTER_PAGE_LENGTH);            /* Set page length to 66 lines per page.    */
    fprintf(stdout, "%s", PRINTER_COMPRESSED_MODE);        /* Force printer into compressed mode       */
    if (ListcMode == LANDSCAPE) {
        fprintf(stdout, "%s", PRINTER_LANDSCAPE);          /* Force printer into LANDSCAPE  mode       */
    }
}


/*
*********************************************************************************************************
*                                      CHECK FOR LISTC COMMAND
*********************************************************************************************************
*/

static BOOLEAN ListcChkCmd(char *s)
{
    char  *p1;                                                  /* Pointer to command name             */
    char  *p2;                                                  /* Pointer to command buffer           */
    CMD   *ptr;                                                 /* Pointer to table of available cmds  */
    char  cmd[80];                                              /* Buffer to hold the command name     */


    cmd[0] = NUL;
    p1     = strchr(s, '$');                                    /* Look for '$' in string              */
    if (p1 != NULLPTR) {                                        /* See if we found a '$'               */
        p1++;                                                   /* We did, position on next character  */
        p2 = &cmd[0];                                           /* Set up to copy command to buffer    */
        while (*p1 != NUL && strchr(" =*", *p1) == NULLPTR) {   /* Copy cmd until '=', '*', ' ' or NUL */
            *p2++ = *p1++;
        }
        *p2 = NUL;                                              /* Append NUL at end of command        */
        ptr = &ListcCmdTable[0];                                /* Search for command in command table */
        while (ptr->CmdName[0] != NUL) {                        /* Go through the whole command table  */
            if (strcmp(ptr->CmdName, cmd) == 0) {               /* See if we found the cmd to execute  */
                ptr->CmdFnct(p1);                               /* We found the command name,          */
                return (TRUE);                                  /* ... execute the function            */
            } else {
                ptr++;                                          /* Look for next entry in cmd table    */
            }
        }
    }
    return (FALSE);
}

/*$PAGE*/
/*
*********************************************************************************************************
*                                    LISTC 'PAGE' COMMAND HANDLER
*********************************************************************************************************
*/

static void ListcNewPage(char *s)
{
    s[0] = s[0];                                           /* Prevent compiler warning                 */
    ListcPageN++;                                          /* Increment the page counter               */
    fprintf(stdout, "%c", PRINTER_FORM_FEED);              /* Issue a form feed                        */
    ListcHdr();                                            /* Make the page header                     */
}


/*
*********************************************************************************************************
*                                  LISTC 'TITLE' COMMAND HANDLER
*********************************************************************************************************
*/

static void ListcChangeTitle(char *s)
{
    char *p1;


    ListcTitle[0] = NUL;                                   /* Initialize the TITLE to empty            */
    p1           = &ListcTitle[0];                         /* Position at beginning of destination     */
    s++;                                                   /* Ignore the '='                           */
    while (*s != NUL && strchr("*", *s) == NULLPTR) {      /* Copy command until '*' or NUL            */
        *p1++ = *s++;
    }
    *p1 = NUL;                                             /* Append NUL terminator at end of command  */
}

/*$PAGE*/
/*
*********************************************************************************************************
*                                        PRINT PAGE HEADER
*********************************************************************************************************
*/

static void ListcHdr(void)
{
    fprintf(stdout, "              ");
    fprintf(stdout, "%-15s         ", ListcDate);
    fprintf(stdout, "%-15s         ", ListcTime);
    fprintf(stdout, "%-20s         ", ListcFileName);
    fprintf(stdout, "  Page: %03d\n", ListcPageN);
    if (ListcTitle[0] != NUL) {
        fprintf(stdout, "              %s\n", ListcTitle);      /* Output TITLE if we have a title     */
    }
    fprintf(stdout, "\n\n");
}


/*
*********************************************************************************************************
*                                          GET CURRENT DATE
*********************************************************************************************************
*/

static void ListcGetDate(char *str)
{
    struct date today;                                     /* Structure to hold current date           */


    getdate(&today);                                       /* Function to get the current DATE         */
    sprintf(str, "%s %2d, %4d", ListcMonths[today.da_mon], today.da_day, today.da_year);
}


/*
*********************************************************************************************************
*                                          GET CURRENT TIME
*********************************************************************************************************
*/

static void ListcGetTime(char *str)
{
    struct time now;                                       /* Structure to hold current time           */


    gettime(&now);                                         /* Function to get the current TIME         */
    sprintf(str, "%02d:%02d:%02d", now.ti_hour, now.ti_min, now.ti_sec);
}
