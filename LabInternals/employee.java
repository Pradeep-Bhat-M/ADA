//import java.util.*;
package LabInternals;

public class employee {
    private String first_name;
    private String last_name;
    private int age;
    private String email;
    private String contact_number;
    private int emp_id;

    public employee(String first_name, String last_name, int age, String email, String contact_number, int emp_id) {
        this.first_name = first_name;
        this.last_name = last_name;
        this.age = age;
        this.email = email;
        this.contact_number = contact_number;
        this.emp_id = emp_id;
    }

    public void setFirst_name(String first_name) {
        this.first_name = first_name;
    }
    public void setLast_name(String last_name) {
        this.last_name = last_name;
    }
    public void setAge(int age) {
        this.age = age;
    }
    public void setContact_number(String contact_number) {
        this.contact_number = contact_number;
    }
    public void setEmail(String email) {
        this.email = email;
    }   
    public void setEmp_id(int emp_id) {
        this.emp_id = emp_id;
    }
    public String getFirst_name() {
        return first_name;
    }
    public String getLast_name() {
        return last_name;
    }
    public int getAge() {
        return age;
    }
    public String getContact_number() {
        return contact_number;
    }
    public String getEmail() {
        return email;
    }
    public int getEmp_id() {
        return emp_id;
    }  
}