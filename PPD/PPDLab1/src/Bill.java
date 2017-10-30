import java.util.ArrayList;
import java.util.List;

/**
 * Created by andrapop on 2017-10-16.
 */
public class Bill {
    List<Purchase> purchases;
    float totalPrice;

    public Bill() {
        purchases = new ArrayList<>();
        totalPrice = 0;
    }
}
