class BinaryCode{
	public :vector<string> decode(string message){
		vector<string> ans;
		if(message.length() == 1){
			if(message[0] == '0'){
				ans.push_back("0");
				ans.push_back("NONE");
			}
			else if(message[0] == '1'){
				ans.push_back("NONE");
				ans.push_back("1");
			}
			else{
				ans.push_back("NONE");
				ans.push_back("NONE");
			}
			return ans;
		}
		
		string p = "",q = message;
		p.append(message.length(), '0');
		int n = message.length();
		for(int i=0;i<n-1;i++){
			if(i == 0){
				p[1] = (q[0] - '0') - (p[0] - '0') + '0';
			}
			else{
				p[i+1] = (q[i] - '0') - (p[i] - '0') - (p[i-1] - '0') + '0';
			}
			if(p[i] > '1' || p[i] < '0'){
				p = "NONE";
				break;
			}
		}
		if((q[n-1] - '0') != (p[n-1] - '0') + (p[n-2] - '0')){
			p[n-1] = '2';
		}
		if(p.length() == n && (p[n-1] > '1' || p[n-1] < '0'))
			p = "NONE";
		ans.push_back(p);

		p = "";
		p.append(message.length(), '1');
		n = message.length();
		for(int i=0;i<n-1;i++){
			if(i == 0){
				p[1] = (q[0] - '0') - (p[0] - '0') + '0';
			}
			else{
				p[i+1] = (q[i] - '0') - (p[i] - '0') - (p[i-1] - '0') + '0';
			}
			if(p[i] > '1' || p[i] < '0'){
				p = "NONE";
				break;
			}
		}
		
		if((q[n-1] - '0') != (p[n-1] - '0') + (p[n-2] - '0')){
			p[n-1] = '2';
		}
		if(p.length() == n && (p[n-1] > '1' || p[n-1] < '0'))
			p = "NONE";
		ans.push_back(p);

		
		return ans;
	}
};
