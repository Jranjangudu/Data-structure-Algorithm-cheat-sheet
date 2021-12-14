// Why And When To Use Abstract Classes and Methods?
// To achieve security - hide certain details and only show the important details of an object.

class Main {
  public static void main(String[] args) {
    // creating bmw class object ;
    Audi a = new Audi();
    a.start();
    a.price = 500000;
    System.out.println( "Audi price :- "+ a.price);
    // creating bmw class object ;
    BMW b = new BMW();
    a.price = 600000;
    System.out.println( "BMW price :- "+ a.price);
    b.start(); 


    // /----------------------------
    Pig myPig = new Pig(); // Create a Pig object
    myPig.animalSound();
    myPig.sleep();
  }
}



class BMW extends Car{
  // here i override start() method of car class;
  @Override
 void start(){
    System.out.println("BMW car started");
  }
}

class Audi extends Car{
  @Override
  void start(){
    System.out.println("Audi car started");
  }
}

// creating abstract class; now class class is called abstract class , so we can't create an object
abstract class Car{
  int price;
  // abstract method , if we create a abstract method , your class most be abstract class
  abstract void start();
}

// The abstract keyword is a non-access modifier, used for classes and methods:

// Abstract class: is a restricted class that cannot be used to create objects (to access it, it must be inherited from another class).

// Abstract method: can only be used in an abstract class, and it does not have a body. The body is provided by the subclass (inherited from).
// An abstract class can have both abstract and regular methods:

// Abstract class
abstract class Animal {
  // Abstract method (does not have a body)
  public abstract void animalSound();
  // Regular method / normal method
  public void sleep() {
    System.out.println("regular method");
  }
}

// Subclass (inherit from Animal)
class Pig extends Animal {
   @Override
  public void animalSound() {
    // The body of animalSound() is provided here
    System.out.println("The pig says: wee wee");
  }
}

