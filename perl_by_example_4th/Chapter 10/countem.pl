# Scriptname: countem.pl
# Open visitor_count for reading first, and then writing
open(FH, "+<visitor_count") || 
		die "Can't open visitor_count: $!\n";
$count=<FH>;           # Read a number from from the file
print "You are visitor number $count.";
$count++;
seek(FH, 0,0) || die;  # Seek back to the top of the file
print FH $count;       # Write the new number to the file
close(FH);