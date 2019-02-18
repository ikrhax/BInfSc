
public class LDate extends Date
{
	LDate (){super();}
	LDate (int y, String m, int d){super(y,m,d);}
	LDate (int y, int m, int d){super(y,m,d);}
	
	public void print()
	{
		System.out.println(nameofday+", "+lmonth+", "+year);
	}
};
