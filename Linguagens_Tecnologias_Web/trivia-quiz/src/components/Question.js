import { Answer } from "./Answer";
import {QuizContext} from '../contexts/quiz'
import { useContext } from "react";
import './styles/Question.css'

export function Question() {
  const [quizState, dispatch] = useContext(QuizContext)
  const currentQuestion = quizState.questions[quizState.currentQuestionIndex];
  return (
    <div className="quest">
      <h1 className="question">{currentQuestion.question}</h1>
      <div className="answers">
        {quizState.answers.map((answer, index) => (
          <Answer
            answerText={answer}
            key={index}
            index={index}
            currentAnswer={quizState.currentAnswer}
            correctAnswer={currentQuestion.correctAnswer}
            onSelectAnswer={(answerText) =>
            dispatch({ type: "SELECT_ANSWER", payload: answerText })
            }
          />
        ))}
      </div>
    </div>
  )
}