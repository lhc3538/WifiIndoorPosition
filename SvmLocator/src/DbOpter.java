import java.io.File;
import java.io.FileOutputStream;
import java.io.IOException;
import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;


public class DbOpter {
	Connection conn = null;
	String sql;
    // MySQL的JDBC URL编写方式：jdbc:mysql://主机名称：连接端口/数据库的名称?参数=值
    // 避免中文乱码要指定useUnicode和characterEncoding
    // 执行数据库操作之前要在数据库管理系统上创建一个数据库，名字自己定，
    // 下面语句之前就要先创建javademo数据库

//    String url = "jdbc:mysql://139.199.27.197:3306/wifi_training_set?"
//            + "user=wifipos&password=iotiot128&useUnicode=true&characterEncoding=UTF8";
    
    String url = "jdbc:mysql://139.199.27.197:3306/wifi_test_set?"
            + "user=wifipos&password=iotiot128&useUnicode=true&characterEncoding=UTF8";
    public void connectDB() throws SQLException {
    	try {
            // 之所以要使用下面这条语句，是因为要使用MySQL的驱动，所以我们要把它驱动起来，
            // 可以通过Class.forName把它加载进去，也可以通过初始化来驱动起来，下面三种形式都可以
            Class.forName("com.mysql.jdbc.Driver");// 动态加载mysql驱动
            // or:
            // com.mysql.jdbc.Driver driver = new com.mysql.jdbc.Driver();
            // or：
            // new com.mysql.jdbc.Driver();

            System.out.println("成功加载MySQL驱动程序");
            // 一个Connection代表一个数据库连接
            conn = DriverManager.getConnection(url);
            // Statement里面带有很多方法，比如executeUpdate可以实现插入，更新和删除等
            Statement stmt = conn.createStatement();

            sql = "select * from level_threemeters";
            ResultSet rs = stmt.executeQuery(sql);// executeQuery会返回结果的集合，否则返回空值
            String str_train = "";
            while (rs.next()) {
//                System.out
//                        .println(rs.getString(1) + "\t" + rs.getString(2));// 入如果返回的是int类型可以用getInt()
                str_train = str_train + rs.getString(2).charAt(1) + " "
                		+ "1:" + rs.getString(3) + " "
                		+ "2:" + rs.getString(4) + " "
                		+ "3:" + rs.getString(5) + " "
                		+ "4:" + rs.getString(6) + " "
                		+ "5:" + rs.getString(7) + " "
                		+ "6:" + rs.getString(8) + " "
                		+ "7:" + rs.getString(9) + " "
                		+ "8:" + rs.getString(10) + " "
                		+ "9:" + rs.getString(11) + "\n";
//	              str_train = str_train + rs.getString(2) + " "
//	        		+ "1:" + rs.getString(3) + " "
//	        		+ "2:" + rs.getString(4) + " "
//	        		+ "3:" + rs.getString(5) + " "
//	        		+ "4:" + rs.getString(6) + " "
//	        		+ "5:" + rs.getString(7) + " "
//	        		+ "6:" + rs.getString(8) + "\n";
	              System.out.print(str_train);// 入如果返回的是int类型可以用getInt()
	              writeFileByFileOutputStream("level_threemeters_test",str_train);
//	              writeFileByFileOutputStream("level_threemeters",str_train);
            }
        } catch (SQLException ex) {
            System.out.println("MySQL操作错误");
            ex.printStackTrace();
        } catch (Exception e) {
            e.printStackTrace();
        } finally {
            conn.close();
        }
    }
    
    public static void writeFileByFileOutputStream(String filePath, String content) throws IOException{  
        File file = new File(filePath);  
        synchronized (file) {  
            FileOutputStream fos = new FileOutputStream(filePath);  
            fos.write(content.getBytes("UTF-8"));  
            fos.close();  
        }  
    } 
}
