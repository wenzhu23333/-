package text_disposal;

import java.awt.Dimension;
import java.awt.GridLayout;
import java.awt.Toolkit;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JPanel;
import javax.swing.JTextArea;
import javax.swing.JTextField;

public class input extends JFrame implements ActionListener{
    public static boolean tap=false; //������¼�Ƿ��Ѿ��������
	public static  String[] name= new String[10];
	private JPanel jp = new JPanel();
	private JLabel jl=new JLabel("����������ʮ���˵����ּ������");
	private JLabel jlb=new JLabel("(�ö��Ÿ���)");
	private JLabel jl1=new JLabel("һ��");
	private JLabel jl2=new JLabel("����");
	private JLabel jl3=new JLabel("����");
	private JLabel jl4=new JLabel("�ģ�");
	private JLabel jl5=new JLabel("�壺");
	private JLabel jl6=new JLabel("����");
	private JLabel jl7=new JLabel("�ߣ�");
	private JLabel jl8=new JLabel("�ˣ�");
	private JLabel jl9=new JLabel("�ţ�");
	private JLabel jl10=new JLabel("ʮ��");
	private JTextField jf1=new JTextField(20);
	private JTextField jf2=new JTextField(20);
	private JTextField jf3=new JTextField(20);
	private JTextField jf4=new JTextField(20);
	private JTextField jf5=new JTextField(20);
	private JTextField jf6=new JTextField(20);
	private JTextField jf7=new JTextField(20);
	private JTextField jf8=new JTextField(20);
	private JTextField jf9=new JTextField(20);
	private JTextField jf10=new JTextField(20);
	private JButton jb = new JButton("ȷ��");
	public  input(){
		
		for(int i=0;i<=9;i++)
		input.name[i]=null;
		this.setVisible(true);
		this.add(jp);
		this.setDefaultCloseOperation(javax.swing.WindowConstants.DISPOSE_ON_CLOSE);
		this.setSize(300,400);
		jp.add(jl);
		jp.add(jlb);
	    jp.add(jl1);
		jp.add(jf1);
		
		jp.add(jl2);
		jp.add(jf2);
		
		jp.add(jl3);
		jp.add(jf3);
		
		jp.add(jl4);
		jp.add(jf4);
		
		jp.add(jl5);
		jp.add(jf5);
		
		jp.add(jl6);
		jp.add(jf6);
		
		jp.add(jl7);
		jp.add(jf7);
		
		jp.add(jl8);
		jp.add(jf8);
		
		jp.add(jl9);
		jp.add(jf9);
		
		jp.add(jl10);
		jp.add(jf10);
		jp.add(jb);
		jb.addActionListener(this);
		int windowWidth = this.getWidth(); //��ô��ڿ�
		int windowHeight = this.getHeight(); //��ô��ڸ�
		Toolkit kit = Toolkit.getDefaultToolkit(); //���幤�߰�
		Dimension screenSize = kit.getScreenSize(); //��ȡ��Ļ�ĳߴ�
		int screenWidth = screenSize.width; //��ȡ��Ļ�Ŀ�
		int screenHeight = screenSize.height; //��ȡ��Ļ�ĸ�
		this.setLocation(screenWidth/2-windowWidth/2, screenHeight/2-windowHeight/2);
	}
	
	public void actionPerformed(ActionEvent e) {
		if(e.getSource()==jb)
		{
			name[0]=jf1.getText();
			name[1]=jf2.getText();
			name[2]=jf3.getText();
			name[3]=jf4.getText();
			name[4]=jf5.getText();
			name[5]=jf6.getText();
			name[6]=jf7.getText();
			name[7]=jf8.getText();
			name[8]=jf9.getText();
			name[9]=jf10.getText();
			input.tap=true;
			StringStat.cal();
			this.dispose();
			// TODO Auto-generated method stub
		}
		else {
			
		}
		
	}
	
	

}
