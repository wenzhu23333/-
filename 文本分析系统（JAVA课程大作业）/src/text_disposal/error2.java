package text_disposal;

import java.awt.Dimension;
import java.awt.Font;
import java.awt.Toolkit;
import java.awt.event.WindowEvent;
import java.awt.event.WindowListener;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JPanel;
public class error2 extends JFrame {
private JPanel pn=new JPanel();
private JLabel jb=new JLabel("����¼�����");
public error2()
{
	this.setVisible(true);
	this.add(pn);
	pn.add(jb);
	jb.setFont(new Font("Dialog",1,20));
	this.setDefaultCloseOperation(javax.swing.WindowConstants.DISPOSE_ON_CLOSE);
	this.setSize(200,100);
	int windowWidth = this.getWidth(); //��ô��ڿ�
	int windowHeight = this.getHeight(); //��ô��ڸ�
	Toolkit kit = Toolkit.getDefaultToolkit(); //���幤�߰�
	Dimension screenSize = kit.getScreenSize(); //��ȡ��Ļ�ĳߴ�
	int screenWidth = screenSize.width; //��ȡ��Ļ�Ŀ�
	int screenHeight = screenSize.height; //��ȡ��Ļ�ĸ�
	this.setLocation(screenWidth/2-windowWidth/2, screenHeight/2-windowHeight/2);
}
}