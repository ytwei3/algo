import java.util.List;
import java.util.ArrayList;

public class UpdateList {
    public static void updateLists(List<List<Integer>> a, List<Integer> b, int c, int d) {
        List<Integer> copy = new ArrayList<>(b); // Create a copy of b
        copy.add(c);
        copy.add(d);
        a.add(copy); // Add the copy to a
    }
}
result.add(new ArrayList<>(path));
result.get(result.size() - 1).add(nums[left]);
result.get(result.size() - 1).add(nums[right]);