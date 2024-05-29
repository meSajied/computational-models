const people = [
    { name: "Alex" },
    { name: "Glen" },
    { name: "John" },
    { name: "Robby" }
  ]

const score = [1, 4, 7, 9]

function zipSort(mainList, secondaryList, sortBy, extra = {}) {
  let zipped = mainList.map((e, i) => [e, secondaryList[i]]);

  // Sort the zipped array
  zipped.sort((a, b) => {
    if (sortBy === "asc") return a[0].name.localeCompare(b[0].name);
    else return b[0].name.localeCompare(a[0].name);
  });

  // Unzip the sorted array back into two separate arrays
  const sortedMainList = [];
  const sortedSecondaryList = [];
  for (let i = 0; i < zipped.length; i++) {
    sortedMainList[i] = zipped[i][0];
    sortedSecondaryList[i] = zipped[i][1];
  }

  return [sortedMainList, sortedSecondaryList];
}

console.log(zipSort(people,score,'assc'));