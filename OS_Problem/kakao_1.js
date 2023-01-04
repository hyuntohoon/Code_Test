function solution(id_list, report, k) {
  var answer = new Array(id_list.length);
  let reportScore = new Array(id_list.length);
  let reportUser = new Array(id_list.length);
  //reportScore.fill(0, 0, parseInt(id_list.length));
  answer.fill(0);
  reportScore.fill(0);
  reportUser.fill("");
  console.log(reportScore);
  console.log(reportUser);
  for (let i = 0; i < report.length; i++) {
    let nowReport = report[i].split(" ");
    let userSplit = reportUser[id_list.indexOf(nowReport[0])].split(" ");
    console.log("aa" + userSplit);
    console.log(reportUser[id_list.indexOf(nowReport[0])].search(nowReport[1]));
    let B = 0;
    for (let j = 0; j < userSplit.length; j++) {
      if (userSplit[j] == nowReport[1]) {
        B = 1;
        break;
      }
    }
    if (B == 0) {
      reportScore[id_list.indexOf(nowReport[1])]++;
      reportUser[id_list.indexOf(nowReport[0])] += nowReport[1] + " ";
    }
  }
  reportScore.forEach((num, index) => {
    console.log(num + " " + index);
    if (num >= k) {
      reportUser.forEach((ele, reportIndex) => {
        if (ele.indexOf(id_list[index]) != -1) {
          answer[reportIndex]++;
        }
      });
    }
  });
  console.log(reportScore);
  console.log(reportUser);
  console.log(answer);
  return answer;
}

function solution(id_list, report, k) {
  const userList = id_list.reduce((result, currentId) => {
    result[currentId] = [0, []];
    return result;
  }, {});

  for (const id of new Set(report)) {
    const [REPORT_ID, ID] = id.split(" ");
    userList[REPORT_ID][1].push(ID);
    userList[ID][0]++;
  }

  const banned = id_list.filter((id) => userList[id][0] >= k);
  const emailList = id_list.map((id) => {
    return userList[id][1].filter((id) => {
      return banned.includes(id);
    }).length;
  });
  console.log(emailList);
  return emailList;
}

let id_list = ["muzi", "frodo", "apeach", "neo"];
let report = ["muzi frodo", "apeach frodo", "frodo neo", "muzi neo", "apeach muzi"];
let k = 2;
id_list = ["con", "ryan", "co"];
report = ["ryan con", "ryan con", "ryan co", "ryan con"];
k = 1;
console.log(solution(id_list, report, k));
