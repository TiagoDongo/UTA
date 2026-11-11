import { Question } from "./Question";
import './styles/Quiz.css'

export function Quiz() {
  return (
    <div className="quiz">
      <div className="score">
        Question 1/8
      </div>

      <Question/>

      <div className="next-button">
        Next Question
      </div>
    </div>
  )
}