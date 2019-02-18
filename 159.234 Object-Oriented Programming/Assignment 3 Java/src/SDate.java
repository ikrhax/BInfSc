
public class SDate extends Date 
{
	SDate (){super();}
	SDate (int y, String m, int d){super(y,m,d);}
	SDate (int y, int m, int d){super(y,m,d);}
	
	public void print()
	{
		System.out.println(day+"/"+month+1+"/"+year);
	}
	
}
