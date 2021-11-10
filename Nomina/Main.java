public class Main {
    public static void main(String[] args) {
        //setup of objects
        /*
        Empleado[] empleados = new Empleado[4];
        empleados[0] = new Administrador("Jorge", 79);
        empleados[1] = new Administrador("Maria", 85);
        empleados[2] = new Jornalero("Monica", 50, 20);
        empleados[3] = new Jornalero("Rodrigo", 60, 15);*/

        Nomina n1 = new Nomina();
        n1.addEmpleado(new Administrador("Jorge", 79));
        n1.addEmpleado(new Administrador("Maria", 85));
        n1.addEmpleado(new Jornalero("Monica", 50, 20));
        n1.addEmpleado(new Jornalero("Rodrigo", 60, 15));
        n1.addEmpleado(new Administrador("Jerry", 15));
        n1.addEmpleado(new Jornalero("Jim", 30, 20));
        n1.addEmpleado(new Administrador("Jessica", 65));
        n1.addEmpleado(new Jornalero("Pam", 70, 30));

        Nomina.empleados[0].calcularSalario(79, 200);
        Nomina.empleados[1].calcularSalario(85, 210);
        Nomina.empleados[2].calcularSalario(50, 150);
        Nomina.empleados[3].calcularSalario(60, 180);
        Nomina.empleados[4].calcularSalario(10, 200);
        Nomina.empleados[5].calcularSalario(40, 250);
        Nomina.empleados[6].calcularSalario(70, 220);
        Nomina.empleados[7].calcularSalario(90, 150);
        
        n1.sortingPorRol_y_Salario();
        
        for (int i = 0; i < Nomina.numeroDeEmpleados; i++) {
            System.out.println("\n" + Nomina.empleados[i]);
        }

        //Use of methods from Nomina
        System.out.println("\nNumero de jornaleros: " + n1.numJornaleros());
        System.out.println("\nNumero de administradores: " + n1.numAdministradores());
        System.out.println("\nCantidad total de empleados: " + Nomina.numeroDeEmpleados);

        System.out.println("\nHoras trabajadas por jornaleros: " + n1.totalHorasJornalero());
        System.out.println("\nHoras trabajadas por adminsitradores: " + n1.totalHorasAdministrador());
        System.out.println("\nHoras trabajadas en total: " + n1.totalHoras());

        System.out.println("\nTotal de pago a jornaleros: " + n1.totalPagoJornalero());
        System.out.println("\nTotal de pago a administradores: " + n1.totalPagoAdministrador());
        System.out.println("\nNomina total a pagar: " + n1.totalPagar());

        n1.darDeBaja(1);
        n1.darDeBaja(7);
        n1.sortingPorRol_y_Salario();

        System.out.println("\n --------------------------");

        //encapsular toString en Nómina
        for (int i = 0; i < Nomina.numeroDeEmpleados; i++) {
            System.out.println("\n" + Nomina.empleados[i]);
        }

        System.out.println("\nNumero de jornaleros: " + n1.numJornaleros());
        System.out.println("\nNumero de administradores: " + n1.numAdministradores());
        System.out.println("\nCantidad total de empleados: " + Nomina.numeroDeEmpleados);

        System.out.println("\nHoras trabajadas por jornaleros: " + n1.totalHorasJornalero());
        System.out.println("\nHoras trabajadas por adminsitradores: " + n1.totalHorasAdministrador());
        System.out.println("\nHoras trabajadas en total: " + n1.totalHoras());

        System.out.println("\nTotal de pago a jornaleros: " + n1.totalPagoJornalero());
        System.out.println("\nTotal de pago a administradores: " + n1.totalPagoAdministrador());
        System.out.println("\nNomina total a pagar: " + n1.totalPagar());

    }

}
