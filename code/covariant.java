import java.lang.*;

class Flower{
    public String whats_Your_Name(){
        return "I have many names and types";
    }
}

class Jasmine extends Flower{
    @Override
    public String whats_Your_Name(){
        return "Jasmine";
    }
}

class Lily extends Flower{
    @Override
    public String whats_Your_Name(){
        return "Lily";
    }
}

class Lotus extends Flower{
    @Override
    public String whats_Your_Name(){
        return "Lotus";
    }
}

class State{
    public Flower your_National_Flower(){
        return new Flower();
    }
}

class WestBengal extends State{
    @Override
    public Jasmine your_National_Flower(){
        return new Jasmine();
    }
}


class AndhraPradesh extends State{
    @Override
    public Lily your_National_Flower(){
        return new Lily();
    }
}

class Karnataka extends State{
    @Override
    public Lotus your_National_Flower(){
        return new Lotus();
    }
}

class test{
    public static void main(String[] args) {
        State ob = new Karnataka();
        Flower ob1 = ob.your_National_Flower();
        System.out.println(ob1.whats_Your_Name());
    }
}
