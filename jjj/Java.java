class A {
   int x = 10;
   int print() {
      return x;
   }
}

class Java{
   public static void main(String[] args){
      int[] k = {1,2,3,4};
      int count = 0;

      for (int i = 0; i < k.length/2+1; i+=2) {
         count += k[i];
      }
      System.out.println(count);
   }
}