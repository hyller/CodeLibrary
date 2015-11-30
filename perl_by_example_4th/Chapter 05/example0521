# Hash slices
%officer= ("NAME"=> "Tom Savage",
           "SSN" => "510-22-3456",
           "DOB" => "05/19/66"
          );

@info=qw(Marine Captain 50000);
@officer{'BRANCH', 'TITLE', 'SALARY'}=@info;
# This is a hash slice
@sliceinfo=@officer{'NAME','BRANCH','TITLE'};
# This is also a hash slice
print "The new values from the hash slice are: @sliceinfo\n\n";
print "The hash now looks like this:\n";
foreach $key ('NAME', 'SSN', 'DOB', 'BRANCH', 'TITLE', 'SALARY'){
	printf "Key: %-10sValue: %-15s\n", $key, $officer{$key};
}
