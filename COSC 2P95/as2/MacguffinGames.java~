package assignment1;
import everybodyintothepool.*;
import java.util.List;
import java.util.Queue;
import java.util.Scanner;
import java.util.InputMismatchException;
//Xinan Wang,5535802

public class MacguffinGames {
 Scanner in;
 
 public MacguffinGames() {
  int choice=-1;
  String first,second,third,fourth;
  List<String> names;
  PoolQueue<String> queue=new ConcretePoolQueue<String>();
  in=new Scanner(System.in);
  do {
   try {
    choice=menu();
    switch (choice) {
    case 1:
     in.nextLine();
     first=yoink("Enter Name: ");
     queue.addSingle(first);
     System.out.println(":-\tAdded ["+first+"]\n");
     break;
    case 2:
     in.nextLine();
     first=yoink("First: ");
     second=yoink("Second: ");
     queue.addPair(first,second);
     System.out.println(":-\tAdded ["+first+","+second+"]\n");
     break;
    case 3:
     in.nextLine();
     first=yoink("First: ");
     second=yoink("Second: ");
     third=yoink("Third: ");
     queue.addTriple(first,second,third);
     System.out.println(":-\tAdded ["+first+","+second+","+third+"]\n");
     break;
    case 4:
     in.nextLine();
     first=yoink("First: ");
     second=yoink("Second: ");
     third=yoink("Third: ");
     fourth=yoink("Fourth: ");
     queue.addQuartet(first,second,third,fourth);
     System.out.println(":-\tAdded ["+first+","+second+","+third+","+fourth+"]\n");
     break;
    case 5:
     System.out.println(":>\t"+queue.removeSingle()+"\n");
     break;
    case 6:
     names=queue.removePair();
     System.out.println(":>\t["+names.get(0)+","+names.get(1)+"]\n");
     break;
    case 7:
     names=queue.removeTriple();
     System.out.println(":>\t["+names.get(0)+","+names.get(1)+","+names.get(2)+"]\n");
     break;
    case 8:
     names=queue.removeQuartet();
     System.out.println(":>\t["+names.get(0)+","+names.get(1)+","+names.get(2)+","+names.get(3)+"]\n");
     break;
    case 9:
     System.out.println("One:\t"+queue.hasSingle());
     System.out.println("Two:\t"+queue.hasPair());
     System.out.println("Three:\t"+queue.hasTriple());
     System.out.println("Four:\t"+queue.hasQuartet());
     System.out.println("Count:\t"+queue.count());
     System.out.println();
     break;
    case 0:
     break;
    default:
     System.out.println("Unrecognized Option");
    }
   }
   catch (InsufficientElementsException iee) {
    System.out.println("Exception caught. Invalid request.\n");
   }
   catch (InputMismatchException ime) {
    in.next();
    System.out.println("Please cease all shenanigans.\n");
   }
  } while (choice!=0);
 }
 
 private int menu() {
  System.out.print("1. Add One");
  System.out.print("\t2. Add Two");
  System.out.print("\t3. Add Three");
  System.out.println("\t4. Add Four");
  System.out.print("5. Remove One");
  System.out.print("\t6. Remove Two");
  System.out.print("\t7. Remove Three");
  System.out.println("\t8. Remove Four");
  System.out.print("\t\t9. Test Options");
  System.out.println("\t0. Quit");
  return in.nextInt();
 }
 
 private String yoink(String msg) {
  System.out.print(msg);
  return in.nextLine();
 }
 
 public static void main(String[] args) {new MacguffinGames();}
}

