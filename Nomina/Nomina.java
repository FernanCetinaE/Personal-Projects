import java.util.Arrays;

public class Nomina{
    public static Empleado[] empleados = new Empleado[100];
    public static Empleado holder;
    public static int numeroDeEmpleados=0;

    /*public Nomina(){
    }*/

    public void addEmpleado(Empleado nuevoEmpleado){
        empleados[numeroDeEmpleados] = nuevoEmpleado;
        numeroDeEmpleados++;
    }

    public double totalPagoJornalero(){
        double cantidadTotal=0;

        for(int i=0;i<numeroDeEmpleados;i++){
            if(empleados[i] != null && empleados[i].getClass() == Jornalero.class){
                cantidadTotal = cantidadTotal + empleados[i].getSalario();
            }
        }

        return cantidadTotal;
    }

    public double totalPagoAdministrador(){
        double cantidadTotal=0;

        for(int i=0;i<numeroDeEmpleados;i++){
            if(empleados[i] != null && empleados[i].getClass() == Administrador.class){
                cantidadTotal = cantidadTotal + empleados[i].getSalario();
            }
        }

        return cantidadTotal;
    }

    public double totalPagar(){
        return totalPagoAdministrador() + totalPagoJornalero();
    }

    public int numJornaleros(){
        int contador=0;

        for(int i=0;i<numeroDeEmpleados;i++){
            if(empleados[i] != null && empleados[i].getClass() == Jornalero.class){
                contador++;
            }
        }

        return contador;
    }

    public int numAdministradores(){
        int contador=0;

        for(int i=0;i<numeroDeEmpleados;i++){
            if(empleados[i] != null && empleados[i].getClass() == Administrador.class){
                contador++;
            }
        }

        return contador;
    }

    public double totalHorasJornalero(){
        double cantidadTotal=0;

        for(int i=0;i<numeroDeEmpleados;i++){
            if(empleados[i] != null && empleados[i].getClass() == Jornalero.class){
            cantidadTotal = cantidadTotal + empleados[i].getNumHorasTrabajadas() + ((Jornalero)empleados[i]).getHorasExtras();
            }
        }

        return cantidadTotal;
    }

    public double totalHorasAdministrador(){
        double cantidadTotal=0;

        for(int i=0;i<numeroDeEmpleados;i++){
            if(empleados[i] != null && empleados[i].getClass() == Administrador.class){
            cantidadTotal = cantidadTotal + empleados[i].getNumHorasTrabajadas();
            }
        }

        return cantidadTotal;
    }

    public double totalHoras(){
        return totalHorasJornalero() + totalHorasAdministrador();
    }

    public void darDeBaja(int posicion){
        numeroDeEmpleados--;
        empleados[posicion] = null;
        sortEmpleadoEliminado();
    }

    public void sortEmpleadoEliminado(){
        //más eficiente si se reccorre a partir del objeto eliminado
        for (int i = 0; i < numeroDeEmpleados ; i++) {
            
                Empleado temporal;
                if(empleados[i]==null && i!=numeroDeEmpleados){
                    temporal = empleados[i+1];
                    empleados[i+1] = null;
                    empleados[i] = temporal; 
                }
            
        } 
    }

    public void sortingPorRol_y_Salario(){
        Arrays.sort(empleados,0,numeroDeEmpleados);
    }

}
