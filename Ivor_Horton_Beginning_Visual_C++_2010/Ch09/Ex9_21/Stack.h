// Stack.h for Ex9_21
// A generic pushdown stack

generic<typename T> ref class Stack
{
private:
  // Defines items to store in the stack
  ref struct Item
  {
    T Obj;                        // Handle for the object in this item
    Item^ Next;                   // Handle for next item in the stack or nullptr

    // Constructor
    Item(T obj, Item^ next): Obj(obj), Next(next){}
  };

  Item^ Top;                      // Handle for item that is at the top

public:
  // Push an object onto the stack
  void Push(T obj)
  {
    Top = gcnew Item(obj, Top);   // Create new item and make it the top
  }

  // Pop an  object off the stack
  T Pop()
  {  
    if(nullptr == Top)            // If the stack is empty
      return T();                 // return null equivalent

    T obj = Top->Obj;             // Get object from item
    Top = Top->Next;              // Make next item the top 
    return obj;
  }
};
