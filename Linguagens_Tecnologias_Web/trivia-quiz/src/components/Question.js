import { Answer } from "./Answer";
import './styles/Question.css'

export function Question() {
  return (
    <div className="quest">
      <h1 className="question">
        Texto da pergunta
      </h1>
      <div className="answers">
        <Answer/>
        <Answer/>
        <Answer/>
        <Answer/>
      </div>
    </div>
  )
}