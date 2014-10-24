package rmi;

//import java.rmi.Naming;
//import java.rmi.RemoteException;
import java.rmi.server.UnicastRemoteObject;
import java.rmi.registry.Registry;
import java.rmi.registry.LocateRegistry;

public class RSMain implements RSInterface {
	public RSMain(){}

	public String sayHello() {
		return "Not sun`s defect.";
	}

	public static void main(String[] args){
		RSMain obj = new RSMain();
		try {

			RSInterface stub = (RSInterface) UnicastRemoteObject.exportObject(obj, 1099);
			
			// Bind the remote object`s stub in the registry.
			Registry registry = LocateRegistry.getRegistry();
			registry.rebind("RSInterface", stub);
			System.out.println("Server Ready");
		} catch (Exception e) {
			System.out.println("Server Exception : " + e.toString());
		}
	}
}


