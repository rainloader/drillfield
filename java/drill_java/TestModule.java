package test;

public class TestModule implements Weather{
	private static final long conditionValue = 500;

	public static void main(String args[])
	{
		TestModule testModule = new TestModule();
		System.out.println(testModule.getConditionValue());
		System.out.println(testModule.describeWeather());
	}

	public long getConditionValue() {
		return conditionValue;
	}


	public String describeWeather(){
		String msg = "partially cloud.";
		return msg;
	}
};
