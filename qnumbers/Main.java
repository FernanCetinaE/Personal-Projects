

public class Main {
    public static void main(String[] args) {
        Racional r1 = new Racional();
        Racional r2 = new Racional();
        Racional r3 = new Racional();

        r1.asignar(1, 2);
        r2.asignar(1, 4);

        r3=r1.sumarRacionales(r2);
        //r3=r1.restarRacionales(r2);
        //r3=r1.multiplicarRacionales(r2);
        //r3=r1.dividirRacionales(r2);

        r3.simplificarRacional();
        r3.imprimir();
    }
}
