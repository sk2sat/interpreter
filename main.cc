#include <iostream>
#include <vector>
#include <string_view>

std::string_view get_token(std::string_view&);
void tokenize(std::string_view, std::vector<std::string_view>&);
void parse(const std::vector<std::string_view>&);

int main(int argc, char **argv){
	std::string code;
	std::vector<std::string_view> toks;
	for(;;){
		std::cout<<"> ";
		std::getline(std::cin, code);
		if(code == "exit") break;
		code+="\n";
		toks = {};
		std::cout<<"code: "<<code<<std::endl;

		tokenize(code, toks);

		std::cout<<"token: "<<std::endl;
		for(auto &t : toks){
			std::cout<<"["<<t<<"] ";
		}
		std::cout<<std::endl;

		parse(toks);
	}
	return 0;
}

void skip_space(std::string_view &code){
	size_t i;
	for(i=0;i<=code.size();i++){
		const auto &c = code[i];
		if(c!=' ' && c!='\t' && c!='\n') break; // 空白以外の文字が来たらbreak
	}
	code.remove_prefix(i); // 先頭の空白部分を取り除く
}

std::string_view get_token(std::string_view &code){
	size_t siz = 0;
	std::string_view ret;

	if(code.empty()) return {};

	skip_space(code); // 余計な空白はスキップ
	while(true){
		switch(code[siz]){
		case ' ': case '\t': case '\n':
			if(siz == 0) skip_space(code);
			ret = code.substr(0,siz);
			code.remove_prefix(siz);
			return ret;
			break;
		// 必ず1文字で区切れる
		case '[': case ']':
		case '(': case ')':
		case '{': case '}':
		case ',': case ';':
			if(siz == 0) siz = 1;
			ret = code.substr(0,siz);
			code.remove_prefix(siz);
			return ret;
			break;
		default:
			siz++;
			break;
		}
	}
	return ret;
}

void tokenize(std::string_view code, std::vector<std::string_view> &toks){
	while(true){
		if(code.empty()) break;
		auto t = get_token(code);
		if(t.empty()) break;
		toks.push_back(t);
	}
}

void parse(const std::vector<std::string_view> &toks){}
