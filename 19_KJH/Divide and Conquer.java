/*  Algorithm : Divide and Conquer
*   Tag : Divide and Conquer
*   Problem : Algospot, ID. QUADTREE
*   URL : https://www.algospot.com/judge/problem/read/QUADTREE#
*/

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;

public class Main {
	static String str;
	static int idx;
	
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		int T = Integer.parseInt(br.readLine());
		
		for (int i = 0; i < T; i++) {
			str = br.readLine();
			idx = 0;
			bw.write(recursion(str.charAt(idx)) + "\n");
		}
		
		bw.flush();
		bw.close();
	}
	
	public static String recursion(char next) {
		char ch = next;
		idx++;
		
		if (ch == 'b' || ch == 'w') {
			return String.valueOf(ch);
		}
		
		String upLeft = recursion(str.charAt(idx));
		String upRight = recursion(str.charAt(idx));
		String downLeft = recursion(str.charAt(idx));
		String downRight = recursion(str.charAt(idx));

		return "x".concat(downLeft).concat(downRight).concat(upLeft).concat(upRight);
	}
} 