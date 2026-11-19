import { useContext } from "react";
import { Question } from "./Question";
import './styles/Quiz.css'
import { QuizContext } from "../contexts/quiz";

export function Quiz() {
  const [quizState, dispatch] = useContext(QuizContext)

  return (
    <div className="quiz">
      {quizState.showResults && (
        <div className="results">
          <div className="congratulations">Congratulations</div>
          <div className="results-info">
            <div>You have completed the quiz.</div>
            <div> 
                You've got {quizState.correctAnswersCount} of{" "}{quizState.questions.length}
            </div>
          </div>
          <div 
            className="next-button"
            onClick={() => dispatch({type: "RESTART"})}
          >
            Restart
          </div>
        </div>
          
      )}
      {!quizState.showResults && (
        <div className="quizQuestion">
          <div className="score">
            Question {quizState.currentQuestionIndex +1}/{quizState.questions.length}
          </div>

          <Question/>

          <div 
            className="next-button"
            onClick={() => dispatch({type: "NEXT_QUESTION"})}
          >
            Next Question
          </div>
        </div>
      )}
    </div>
  )
}