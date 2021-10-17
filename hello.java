class Simple{  
    public static void main(String args[]){  
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        System.out.println("Enter a text");
        String name = reader.readLine();
        System.out.println("You Typed" +name);
    }  
}  
