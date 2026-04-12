import java.util.*;

class UserService {
    private List<User> users;

    public UserService(List<User> users) {
        this.users = users;
    }

    public User findByName(String name) {
        return users.stream()
                .filter(u -> u.name.equals(name))
                .findFirst()
                .orElse(null);
    }

    public List<User> getActiveUsers() {
        return users.stream()
                .filter(u -> u.active && u.name != null)
                .toList();
    }
 
    public void printUsers() {
        for (User u : users) {
            if (u.active) {
                System.out.println("Active: " + u.name);
            } else {
                System.out.println("Inactive: " + u.name);
            }
        }
    }
}

class User {
    int id;
    String name;
    boolean active;

    User(int id, String name, boolean active) {
        this.id = id;
        this.name = name;
        this.active = active;
    }
}

public class Main {
    public static void main(String[] args) {
        List<User> users = Arrays.asList(
                new User(1, "Sumit", true),
                new User(2, "Alex", false),
                new User(3, "Dev", true));

        UserService service = new UserService(users);

        User user = service.findByName("Sumit");
        System.out.println(user != null ? user.name : "Not found");

        service.printUsers();
    }
}