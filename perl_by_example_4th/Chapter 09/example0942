# Backreferencing and greed
$fruit="apples pears peaches plums";
$fruit =~ /(.*)\s(.*)\s(.*)/;   
print "$1\n";
print "$2\n";
print "$3\n";
print "-" x 30, "\n";
$fruit="apples pears peaches plums";
$fruit =~ /(.*?)\s(.*?)\s(.*?)\s/;   # Turn off greedy quantifier
print "$1\n";
print "$2\n";
print "$3\n";
