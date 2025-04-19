public class ArrayImplementation {
    static final int TABLE_SIZE = 10;
    static String[] keys = new String[TABLE_SIZE];
    static String[] values = new String[TABLE_SIZE];

    public static int hash(String key) {
        int hash = 0;
        for (int i = 0; i < key.length(); i++) {
            hash += key.charAt(i);
        }
        return hash % TABLE_SIZE;
    }

    public static void insert(String key, String value) {
        int index = hash(key);
        while (keys[index] != null) {
            if (keys[index].equals(key)) {
                values[index] = value;
                return;
            }
            index = (index + 1) % TABLE_SIZE;
        }
        keys[index] = key;
        values[index] = value;
    }

    public static String get(String key) {
        int index = hash(key);
        while (keys[index] != null) {
            if (keys[index].equals(key)) {
                return values[index];
            }
            index = (index + 1) % TABLE_SIZE;
        }
        return null;
    }

    public static void printMap() {
        for (int i = 0; i < TABLE_SIZE; i++) {
            if (keys[i] != null) {
                System.out.println(keys[i] + " : " + values[i]);
            }
        }
    }

    public static void main(String[] args) {
        insert("apple", "fruit");
        insert("banana", "fruit");
        insert("carrot", "vegetable");
        System.out.println(get("apple"));
        System.out.println(get("banana"));
        System.out.println(get("carrot"));
        // printMap();
    }
}
