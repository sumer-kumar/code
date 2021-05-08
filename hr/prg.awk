{
	sumocreds = sunocreds = $3
	if($2 == "A"){
	sgrade = sgrade + 9*$3;
	}
	else if ($2 == "B"){
	sgrade = sgrade + 7*$3;
	}
	else if($2 == "C"){
	sgrade = sgrade + 6*$3;
	}
}

END {
	#print sgrade;
	#print sumocreds;
	grades = sgrade/sumocreds;

	printf("GPA of XYZ is == %.3f",grades);
	
}