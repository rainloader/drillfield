package rmi;

import java.rmi.Remote;
import java.rmi.RemoteException;

public interface RSInterface extends Remote { // must inherit Remote
	String sayHello() throws RemoteException;
}



