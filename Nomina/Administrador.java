public class Administrador extends Empleado{
    private double porcentajeCompensacion;

    public Administrador(String nombre, double numHorasTrabajadas){
        super(nombre,numHorasTrabajadas);
    }

    public void setPorcentajeCompensacion(){
        if(super.getNumHorasTrabajadas() < 80){
            this.porcentajeCompensacion = .2;
        }else{
            this.porcentajeCompensacion = .3;
        }
    }

    public double getPorcentajeCompensacion(){
        return this.porcentajeCompensacion;
    }

    public double calcularSalario(int numHorasTrabajadas, double tarifa) {
        setPorcentajeCompensacion();
        return super.calcularSalario(numHorasTrabajadas, tarifa *(1+this.porcentajeCompensacion));
    }

    @Override
    public String toString() {
    return super.toString() + "\nPorcentaje compensacion: " + this.porcentajeCompensacion;
    }
    
}