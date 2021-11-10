public class Jornalero extends Empleado{
    private double horasExtras;

    public Jornalero(String nombre, double numHorasTrabajadas, double horasExtras){
        super(nombre,numHorasTrabajadas);
        this.horasExtras = horasExtras;
    }

    public void setHorasExtras(double horasExtras){
        this.horasExtras = horasExtras;
    }

    public double getHorasExtras(){
        return this.horasExtras;
    }

    public double calcularSalario(int numHorasTrabajadas, double tarifa) {
        double salarioFinal = numHorasTrabajadas*tarifa + this.horasExtras*2*tarifa;
        super.setSalario(salarioFinal);
        return salarioFinal;
    }

    @Override
    public String toString() {
    return super.toString() + "\nHoras extras: " + this.horasExtras;
    }

}
