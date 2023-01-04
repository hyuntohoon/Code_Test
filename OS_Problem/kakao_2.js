function solution(fees, records) {
  var answer = [];
  records.forEach((temp) => {
    let [time, car, type] = temp.split(" ");
    console.log(`${time} ${car} ${type}`);
    const [hour, minute] = time.split(":");
  });

  return answer;
}

function solution(fees, records) {
  const cars = {};

  records.forEach((v) => {
    // 정보 쪼개기
    let [time, car, type] = v.split(" ");

    const [hour, minute] = time.split(":");

    // 분으로 바꾸기
    time = hour * 60 + Number(minute);

    // 처음 조회되는 차량일 시
    if (!cars[car]) {
      cars[car] = { time: 0, car };
    }

    cars[car].type = type;

    if (type == "OUT") {
      cars[car].time += time - cars[car].lastInTime;
      return;
    }

    cars[car].lastInTime = time;
  });

  return Object.values(cars)
    .sort((a, b) => {
      console.log("a " + a.car);
      console.log("b " + b.car);
      a.car - b.car;
    })
    .map((v) => {
      // 차량이 최종적으로 나가지 않았을 때
      if (v.type == "IN") {
        v.time += 1439 - v.lastInTime;
      }

      // 기본시간을 넘지 않았을 때
      if (fees[0] > v.time) {
        return fees[1];
      }

      return fees[1] + Math.ceil((v.time - fees[0]) / fees[2]) * fees[3];
    });
}

const fees = [180, 5000, 10, 600];
const records = [
  "05:34 5961 IN",
  "06:00 0000 IN",
  "06:34 0000 OUT",
  "07:59 5961 OUT",
  "07:59 0148 IN",
  "18:59 0000 IN",
  "19:09 0148 OUT",
  "22:59 5961 IN",
  "23:00 5961 OUT",
];

solution(fees, records);
