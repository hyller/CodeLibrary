package Math::BigFloat;
use Math::BigInt;

use Exporter;  # Just for use to be happy
@ISA = (Exporter);

use overload
'+'    =>  sub {new Math::BigFloat &fadd},
'-'    =>  sub {new Math::BigFloat
	         $_[2]? fsub($_[1],${$_[0]}) : fsub(${$_[0]},$_[1])},
'<=>'  =>  sub {new Math::BigFloat
	         $_[2]? fcmp($_[1],${$_[0]}) : fcmp(${$_[0]},$_[1])},
'cmp'  =>  sub {new Math::BigFloat
	         $_[2]? ($_[1] cmp ${$_[0]}) : (${$_[0]} cmp $_[1])},
'*'    =>  sub {new Math::BigFloat &fmul},
'/'    =>  sub {new Math::BigFloat 
	         $_[2]? scalar fdiv($_[1],${$_[0]}) :
                scalar fdiv(${$_[0]},$_[1])},
'neg'  =>  sub {new Math::BigFloat &fneg},
'abs'  =>  sub {new Math::BigFloat &fabs},
qw(
	""   stringify
	0+   numify)    # Order of arguments unsignificant
	;

sub new {
 		my ($class) = shift;
 		my ($foo) = fnorm(shift);
		panic("Not a number initialized to Math::BigFloat") 
	       if $foo eq "NaN";

	bless \$foo, $class;
}

    < Methods continue here. Module was too long to put here> 

# addition
sub fadd { #(fnum_str, fnum_str) return fnum_str
	local($x,$y) = (fnorm($_[$[]),fnorm($_[$[+1]));
	if ($x eq 'NaN' || $y eq 'NaN') {
		NaN';
	} else {
		local($xm,$xe) = split('E',$x);
		local($ym,$ye) = split('E',$y);
		($xm,$x e,$ym,$ye) = ($ym,$ye,$xm,$xe) if ($xe < $ye);
		&norm(Math::BigInt::badd($ym,$xm.('0' x ($xe-$ye))),$ye);
	}
}

    < Methods continue here>

# divisionbb
# args are dividend, divisor, scale (optional)
# result has at most max(scale, length(dividend),
# length(divisor)) digits
sub fdiv    #(fnum_str, fnum_str[,scale]) return fnum_str
{
	local($x,$y,$scale) = (fnorm($_[$[]), 
	                       fnorm($_[$[+1]),$_[$[+2]);
	if ($x eq 'NaN' || $y eq 'NaN' || $y eq '+0E+0') {
		'NaN';
	} else {
		local($xm,$xe) = split('E',$x);
		local($ym,$ye) = split('E',$y);
		$scale = $div_scale if (!$scale);
		$scale = length($xm)-1 if (length($xm)-1 > $scale);
		$scale = length($ym)-1 if (length($ym)-1 > $scale);
		$scale = $scale + length($ym) - length($xm);
		&norm(&round(Math::BigInt::bdiv($xm.('0' x $scale),$ym),
		                                $ym),$xe-$ye-$scale);
	}
}