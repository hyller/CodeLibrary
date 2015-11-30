# Assigning keys and values to a hash
%department = (
	            "Eng" => "Engineering", 
	            "M"   => "Math",
	            "S"   => "Science",
	            "CS"  => "Computer Science",
	            "Ed"  => "Education",
	           );     
$department = $department{'M'}; # Either single or double quotes                   
                                # ok for the keys
$school = $department{'Ed'};
print "I work in the $department section\n" ;
print "Funds in the $school department are being cut.\n";
print qq/I'm currently enrolled in a $department{'CS'} course.\n/;
print qq/The department hash looks like this:\n/;
print %department, "\n";   # The printout is not in the expected
                           # order due to internal hashing
