package Skey;

import javax.swing.*;
import java.security.MessageDigest;
import java.security.NoSuchAlgorithmException;

public class skey  {
     private String r; //�û�����������r
     private  int n; //n�ε�½
     private String[] hashlink = new String[n+1];

     public skey(int n,String r)
     {
         this.n = n;
         this.r = r;
         hashlink = new String[n+1];

     }
     public void CalHashlinkByMD5()
     {

        try {

            hashlink[0] = this.MD5(r);
            for (int i = 1; i < n + 1; i++) {
                hashlink[i] = this.MD5(hashlink[i-1]);
            }
        }
        catch (Exception e)
        {}
     }
     public String MD5(String src) throws Exception{
         byte[] input = src.getBytes();
             MessageDigest digest = MessageDigest.getInstance("MD5");
             digest.update(input);
             input = digest.digest();
             int length = input.length;
             StringBuffer strBuff = new StringBuffer();
             for (int i = 0; i < length; i++) {
                 int val = ((int) input[i]) & 0xff;
                 if (val < 16) {
                     strBuff.append("0");
                 }
                 strBuff.append(Integer.toHexString(val));
             }
             return strBuff.toString();

     }


    public void setN(int n) {
        this.n = n;
    }

    public void setR(String r) {
        this.r = r;
    }

    public String[] getHashlink() {
        return hashlink;
    }

    public int getN() {
        return n;
    }


    public static void main(String[] args) throws Exception
    {
        String msg = JOptionPane.showInputDialog("�������ʼr");
        String s = JOptionPane.showInputDialog("������ʹ�ô���");
       int  n = Integer.parseInt(s);
        skey k = new skey(n,msg);
        k.CalHashlinkByMD5();
        String[] output = k.getHashlink();
        for (String e:output)
            System.out.println(e);
        int flag = 0;
        String newStr = output[n-1];
        int i = n;
        while(true)
        {
            newStr = output[i];
            String m = JOptionPane.showInputDialog("���������");
            if(newStr.equals(k.MD5(m)))
                JOptionPane.showMessageDialog(null, "��" + (flag+1) + "�ε�½�ɹ�!");
			else
           {
            JOptionPane.showMessageDialog(null,  "��½ʧ��!");
            continue;
           }
        if (flag == n-1) {
            JOptionPane.showMessageDialog(null, "��̬������ʹ�����");
            break;
        }

          flag++;
            i--;
        }
    }

}
