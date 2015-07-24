/*
Platform SDK: Windows System Information 

See: http://msdn.microsoft.com/library/default.asp?url=/library/en-us/sysinfo/sysinfo_5r76.asp


*/

#include <windows.h>
#ifdef TEST
# include <stdio.h>
#endif /* TEST */
#include <gw32.h>

#define BUFSIZE 80

#define VIDSIZE  13
static const char * vid_cyrix =   "CyrixInstead";
static const char * vid_centaur = "CentaurHauls";
static const char * vid_rise =    "RiseRiseRise";
static const char * vid_intel =   "GenuineIntel";
static const char * vid_amd =     "AuthenticAMD";
static const char * vid_tmx86 =   "GenuineTMx86";
static const char * vid_geode =   "Geode by NSC";
static const char * vid_umc =     "UMC UMC UMC ";
static const char * vid_amd2 =    "AMD ISBETTER";
static const char * vid_amd3 =    "DEI         ";
static const char * vid_amd4 =    "NexGenerationAMD";
static const char * vid_nexgen =  "NexGenDriven";

#define cpuid(op,a,b,c,d)\
  __asm__("cpuid": "=a" (a), "=b" (b), "=c" (c), "=d" (d) : "a" (op));

static unsigned long MaxEax;

void GetVendorID (char *vid)
{
  unsigned long ebx, ecx, edx, zerobyte;

  cpuid (0, MaxEax, ebx, ecx, edx);
  memcpy (vid, &ebx, 4);
  memcpy (vid+4, &edx, 4);
  memcpy (vid+8, &ecx, 4);
  zerobyte = 0;
  memcpy (vid+12, &zerobyte, 1);
}

BOOL GetMachInfo(LPSTR MachineName, LPSTR ProcessorName)
{
   SYSTEM_INFO sysinf;
   int family, model, stepping;
   char VendorId [VIDSIZE+2];

   ZeroMemory(&sysinf, sizeof(SYSTEM_INFO));
   GetSystemInfo(&sysinf);
   family = sysinf.wProcessorLevel;
   model = HIBYTE(sysinf.wProcessorRevision);
   stepping = LOBYTE(sysinf.wProcessorRevision);
   
/*
   fprintf(stderr, "Pagesize: %#x\n", sysinf.dwPageSize);
   fprintf(stderr, "MinimumApplicationAddress: %#x\n", sysinf.lpMinimumApplicationAddress);
   fprintf(stderr, "MaximumApplicationAddress: %#x\n", sysinf.lpMaximumApplicationAddress);
   fprintf(stderr, "NumberOfProcessors: %Ld\n", sysinf.dwNumberOfProcessors);
   fprintf(stderr, "AllocationGranularity: %#x\n", sysinf.dwAllocationGranularity);
   fprintf(stderr, "ProcessorArchitecture: %Ld: ", sysinf.wProcessorArchitecture);
*/
   switch (sysinf.wProcessorArchitecture) {
   	case PROCESSOR_ARCHITECTURE_UNKNOWN:
	   strcpy(MachineName, "unknown");
	   break;
	case PROCESSOR_ARCHITECTURE_INTEL:
	   strcpy(MachineName, "ix86-pc");
	   break;
	case PROCESSOR_ARCHITECTURE_MIPS:
	   strcpy(MachineName, "mips");
	   break;
	case PROCESSOR_ARCHITECTURE_ALPHA:
	   strcpy(MachineName, "alpha");
	   break;
	case PROCESSOR_ARCHITECTURE_PPC:
	   strcpy(MachineName, "ppc");
	   break;
	case PROCESSOR_ARCHITECTURE_IA64:
	   strcpy(MachineName, "IA64");
	   break;
	case PROCESSOR_ARCHITECTURE_IA32_ON_WIN64:
	   strcpy(MachineName, "IA32 on Win64");
	   break;
	case PROCESSOR_ARCHITECTURE_AMD64:
	   strcpy(MachineName, "amd64");
	   break;
	case PROCESSOR_ARCHITECTURE_SHX:
	   strcpy(MachineName, "sh");
	   break;
	case PROCESSOR_ARCHITECTURE_ARM:
	   strcpy(MachineName, "arm");
	   break;
	case PROCESSOR_ARCHITECTURE_ALPHA64:
	   strcpy(MachineName, "alpha64");
	   break;
	case PROCESSOR_ARCHITECTURE_MSIL:
	   strcpy(MachineName, "msil");
	   break;
	default: 
	   strcpy(MachineName, "unknown");
	   break;
	}
/*
   fprintf(stderr, "ProcessorLevel:       %Ld\n", family);
   fprintf(stderr, "ProcessorRevision:    %#x\n", sysinf.wProcessorRevision);
   fprintf(stderr, "   ProcessorModel:    %d\n", model);
   fprintf(stderr, "   ProcessorStepping: %d\n", stepping);
   
   fprintf(stderr, "Processor: ");
*/
   if (sysinf.wProcessorArchitecture == PROCESSOR_ARCHITECTURE_INTEL)
	switch(family) {
    case 3:
	   strcpy(MachineName, "i386-pc");
       break;
    case 4:
	   strcpy(MachineName, "i486-pc");
       break;
    case 5:
	   strcpy(MachineName, "i586-pc");
       break;
    case 6:
       strcpy(MachineName, "i686-pc");
       break;
    case 7:
       strcpy(MachineName, "i786-pc");
       break;
    case 15:
		strcpy(MachineName, "i786-pc");
		break;
   default:
		strcpy(MachineName, "ix86-pc");
   }
 		
	GetVendorID(VendorId);
#ifdef TEST
	fprintf(stderr, "VendorId: %s\n", VendorId);
#endif /* TEST */
   if (!strcmp(VendorId, vid_cyrix))
   	  strcpy(ProcessorName, "Cyrix");
   else if (!strcmp(VendorId, vid_centaur))
   	  strcpy(ProcessorName, "Centaur");
   else if (!strcmp(VendorId,  vid_rise))
   	  strcpy(ProcessorName, "Rise");
   else if (!strcmp(VendorId,  vid_intel))
   	  strcpy(ProcessorName, "Intel");
   else if (!strcmp(VendorId,  vid_amd))
   	  strcpy(ProcessorName, "AMD");
   else if (!strcmp(VendorId,  vid_tmx86))
   	  strcpy(ProcessorName, "Transmeta");
   else if (!strcmp(VendorId,  vid_geode))
   	  strcpy(ProcessorName, "Geode");
   else if (!strcmp(VendorId, vid_umc))
   	  strcpy(ProcessorName, "UMC");
   else if (!strcmp(VendorId, vid_amd2))
   	  strcpy(ProcessorName, "AMD");
   else if (!strcmp(VendorId, vid_amd3))
   	  strcpy(ProcessorName, "AMD");
   else if (!strcmp(VendorId, vid_amd4))
   	  strcpy(ProcessorName, "AMD");
   else if (!strcmp(VendorId, vid_nexgen))
   	  strcpy(ProcessorName, "NexGen");
   else 
   	  strcpy(ProcessorName, "Unknown");

   return TRUE;
}	


#ifdef TEST
int
main ()
{
	char MachineName [BUFSIZE];
	char ProcessorName [BUFSIZE];
	
	if (GetMachInfo(MachineName, ProcessorName)) {
		fprintf(stderr, "Machine:   %s\n", MachineName);
		fprintf(stderr, "Processor: %s\n", ProcessorName);
	}
	return 0;
}
#endif /* TEST */
