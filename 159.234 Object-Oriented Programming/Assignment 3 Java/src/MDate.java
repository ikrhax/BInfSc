
public class MDate extends Date 
{
	MDate (){super();}
	MDate (int y, String m, int d){super(y,m,d);}
	MDate (int y, int m, int d){super(y,m,d);}
	
	public void print()
	{
		System.out.println(day+"-"+smonth+"-"+year);
	}
}
