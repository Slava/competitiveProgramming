#include <cstdio>
#include <cstring>
#include <map>
#include <string>

using namespace std;

char s[2000], t[2000], name[2000];
int n, day;
map<int, string>Map;
int main() {
	Map[21] = " A";
	Map[22] = "A'";
	Map[23] = " B";
	Map[24] = "B'";
	Map[25] = " C";
	Map[26] = "C'";
	Map[27] = " D";
	Map[28] = "Olympiad";
	FILE *list = fopen("list", "r");
	for (; fscanf(list, "%s", s) == 1; ) {
		t[0] = 0; strcat(t, s); strcat(t, ".xml");
		
		sscanf(s + 2, "%d", &n);
		day = n % 100;
		n /= 100;
		name[0] = 0;
		sprintf(name, "LKSH 2011. August. Par. %s: Day %d", Map[n].c_str(), day);

		freopen(t, "w", stdout);
		puts("<?xml version=\"1.0\" encoding=\"utf-8\" ?>");
		printf("<contest id=\"%s\"\n", s);
		printf("\
         disable_team_password=\"yes\"\n\
         simple_registration=\"yes\"\n\
         personal=\"yes\"\n\
         allow_reg_data_edit=\"yes\"\n\
         managed=\"yes\"\n\
         run_managed=\"yes\">\n\
  <name>%s</name>\n\
  <name_en>%s</name_en>\n\
  <sched_time>2011/08/21 18:00:00</sched_time>\n\
  <register_access default=\"allow\"/>\n\
  <users_access default=\"allow\"/>\n\
  <master_access default=\"allow\"/>\n\
  <judge_access default=\"allow\"/>\n\
  <team_access default=\"allow\"/>\n\
  <serve_control_access default=\"allow\"/>\n\
  <caps>\n\
    <cap login = \"slava\">\n\
      MASTER_SET,\n\
    </cap>\n\
  </caps>\n\
</contest>\n\
", name, name);
	}
}

