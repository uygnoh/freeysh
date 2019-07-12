关于大小月和润年的判断

hour = 0;
day++;
week++;

switch (mon)
{
	case 1:  if(day==32) day=1; mon++; break;
	case 3:  if(day==32) day=1; mon++; break;
	case 5:  if(day==32) day=1; mon++; break;
	case 7:  if(day==32) day=1; mon++; break;
	case 8:  if(day==32) day=1; mon++; break;
	case 10: if(day==32) day=1; mon++; break;
	case 12: if(day==32) day=1; mon++; break;
	case 4:  if(day==31) day=1; mon++; break;
	case 6:  if(day==31) day=1; mon++; break;
	case 9:  if(day==31) day=1; mon++; break;
	case 11: if(day==31) day=1; mon++; break;
	
	
	
	case 2: x = 20*100+year;
		if ((x%4 == 0 && x%100 != 0) || x%400 == 0)
		{
			if (day == 30)
			{
				day = 1;
				month++;
				break;
			}
			else if (day == 29)
			{
				day = 1;
				month++;
				break;
			}
		}
		
	
}
