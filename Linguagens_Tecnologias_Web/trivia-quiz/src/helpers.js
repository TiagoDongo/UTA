export const shuffleAnswers = (question) => {
  const unshuffleAnswers = [
    question.correctAnswer,
    ...question.incorrectAnswers
  ];

  return unshuffleAnswers.map((unshuffleAnswer) => ({
    sort: Math.random(),
    value: unshuffleAnswer
  })).sort(
    (a, b) => a.sort - b.sort
  ).map(
    (a) => a.value
  );
}