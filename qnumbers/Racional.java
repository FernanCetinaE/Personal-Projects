

public class Racional {
    private int numerador;
    private int denominador;

    Racional(){};

    public void asignar(int n,int d){
        this.numerador = n;
        this.denominador = d;
    };

    public void imprimir(){
        System.out.println(this.numerador + "/" + this.denominador + "\n");
    };

    public void simplificarRacional(){
        int i;
        int contador=2;
    
        if (numerador>=denominador)
        {
            i=denominador;
        }else{
            i=numerador;
        }
        
        while (contador<=i)
        {
            if ( (numerador%contador==0) && (denominador%contador==0) )
            {
                numerador=numerador/contador;
                denominador=denominador/contador;
            }else{
                contador++;
            }
        }        
    };

    public Racional sumarRacionales(Racional r){
        Racional aux= new Racional();
        aux.numerador = numerador*r.denominador + denominador*r.numerador;
        aux.denominador = denominador*r.denominador;
        return aux;
    };

    public Racional restarRacionales(Racional r){
        Racional aux= new Racional();
        aux.numerador = numerador*r.denominador + denominador*r.numerador;
        aux.denominador = denominador*r.denominador;
        return aux;
    };

    public Racional multiplicarRacionales(Racional r){
        Racional aux= new Racional();
        aux.numerador = numerador*r.numerador;
        aux.denominador = denominador*r.denominador;
        return aux;
    };

    public Racional dividirRacionales(Racional r){
        Racional aux= new Racional();
        aux.numerador = numerador*r.denominador;
        aux.denominador = denominador*r.numerador;
        return aux;
    };
}
