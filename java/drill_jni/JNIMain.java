package jni;

public class JNIMain {
	static
	{
		System.loadLibrary("JNIMain");
		System.out.println("=== library was loaded");
	}
	
	public native void printJNIMessage();
	public native void printJNIString(String str);
	public static void main(String[] args) throws Exception
	{
		JNIMain obj = new JNIMain();
		obj.printJNIMessage();
		obj.printJNIString("JNI string");
		
	}
}
