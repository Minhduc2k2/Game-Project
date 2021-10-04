package TaiXiu;

import java.io.FileInputStream;
import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.text.NumberFormat;
import java.util.Locale;
import java.util.Random;
import java.util.Scanner;

public class Entry {
    public static void main(String[] args) throws IOException {
        double money = 5000000;
        Scanner sc = new Scanner(System.in);

//        String content = new String(Files.readAllBytes(Paths.get("TaiXiu/input1.txt")));
//        System.out.println(content);

        Locale locale = new Locale("vi", "VN");
        NumberFormat numf = NumberFormat.getCurrencyInstance(locale);

        String choice = "1";
        System.out.println("-----------Welcome To Summoner's Rift-----------");
        do {
            System.out.println("-----------Nhập lựa chọn của bạn-----------");
            System.out.println("Nhập phím 1 để chơi.");
            System.out.println("Nhập phím bất kì để thoát.");
            choice = sc.nextLine();
            if (choice.equals("1")) {
                System.out.println("*** Bắt Đầu Chơi ***");
                System.out.println("*** Số dư hiện tại: " + numf.format(money));
                double amount;
                do {
                    System.out.println("!!!Lưu ý 0 < số tiền cược <= " + numf.format(money));
                    System.out.print("*** Nhập số tiền muốn cược: ");
                    amount = sc.nextDouble();
                } while (amount <= 0 || amount > money);
                int taixiu = -1;
                do {
                    System.out.println("Chọn 1: Tài || Chọn 2: Xỉu");
                    System.out.print("Chọn: ");
                    taixiu = sc.nextInt();
                    sc.nextLine();
                } while (taixiu != 1 && taixiu != 2);

                //Tung xúc xắc
                Random xucsac1 = new Random();
                Random xucsac2 = new Random();
                Random xucsac3 = new Random();

                int num1 = xucsac1.nextInt(5) + 1;
                int num2 = xucsac2.nextInt(5) + 1;
                int num3 = xucsac3.nextInt(5) + 1;
                int sum = num1 + num2 + num3;
                // Tính toán kết quả:
                System.out.println("Xúc sắc 1: " + num1 + " - Xúc sắc 2: " + num2 + " - Xúc sắc 3: " + num3);
                if (sum == 3 || sum == 18) {
                    System.out.println("******Tổng là: " + sum + " =>Nhà cái ăn, bạn đã thua lượt này.");
                    System.out.println("Cờ bạc, người không chơi là người ko bao giờ thắng; người thua là người chưa thắng; người bỏ cuộc là thất bại; còn chơi là còn gỡ ,còn nước còn tát :))");
                    money -= amount;
                    System.out.println("Số dư còn lại là: " + numf.format(money));
                } else if (sum >= 4 && sum <= 10) {
                    System.out.println("******Tổng là: " + sum + " =>Xỉu");
                    if (taixiu != 2) {
                        System.out.println("Bạn đã thua lượt này");
                        System.out.println("Cờ bạc, người không chơi là người ko bao giờ thắng; người thua là người chưa thắng; người bỏ cuộc là thất bại; còn chơi là còn gỡ ,còn nước còn tát :))");
                        money -= amount;
                    } else {
                        System.out.println("Bạn đã thắng lượt này");
                        System.out.println("Bạn là nhất nhá, nhất bạn luôn :>");
                        money += amount;
                    }
                    System.out.println("Số dư còn lại là: " + numf.format(money));
                } else {
                    System.out.println("******Tổng là: " + sum + " =>Taì");
                    if (taixiu != 1) {
                        System.out.println("Bạn đã thua lượt này");
                        System.out.println("Cờ bạc, người không chơi là người ko bao giờ thắng; người thua là người chưa thắng; người bỏ cuộc là thất bại; còn chơi là còn gỡ ,còn nước còn tát :))");
                        money -= amount;
                    } else {
                        System.out.println("Bạn đã thắng lượt này");
                        System.out.println("Bạn là nhất nhá, nhất bạn luôn :>");
                        money += amount;
                    }
                    System.out.println("Số dư còn lại: " + numf.format(money));
                }
                if (money == 0) {
                    System.out.println("Bạn đã phá sản Y_Y");
                    choice = "0";
                }
            } else {
                System.out.println("Bạn ra về với số tiền: " + numf.format(money));
                System.out.println("See You Again ^^");
            }
        } while (choice.equals("1"));
    }
}
