const API_KEY = "";
const API_URL = `https://api.themoviedb.org/3/discover/movie?sort_by=popularity.desc&api_key=${API_KEY}&page=1`;
const IMG_PATH = "https://image.tmdb.org/t/p/w1280";
const SEARCH_API = `https://api.themoviedb.org/3/search/movie?api_key=${API_KEY}&query=`;

const moviesContainer = document.getElementById("movies");
const form = document.getElementById("search-form");
const searchInput = document.getElementById("search");

const container = document.querySelector(".container");
const menuToggle = document.getElementById("menu-toggle");

menuToggle.addEventListener("click", () => {
  const isOpen = container.classList.toggle("sidebar-open");
});

function getRateClass(vote) {
  if (vote >= 8) return "green";
  if (vote >= 5) return "orange";
  return "red";
}

async function getMovies(url = API_URL) {
  try {
    const response = await fetch(url);
    if (!response.ok) {
      throw new Error(`Erro ao buscar filmes: ${response.status}`);
    }

    const data = await response.json();
    const movies = data.results;

    if (!Array.isArray(movies) || movies.length === 0) {
      moviesContainer.innerHTML = "<p>Nenhum filme disponivel no momento</p>";
      return;
    }

    moviesContainer.innerHTML = movies
      .map(
        (movie) => `
        <div class="movie-card">
          <img class="cover" src="${IMG_PATH + movie.poster_path}" >

          <div class="overview">
            <h3>Sinopse</h3>
            <p>${movie.overview}</p>
          </div>

          <div class="movie-infos">
            <h3 class="movie-title">${movie.title}</h3>
            <span class="movie-rate ${getRateClass(movie.vote_average)}">
              ${movie.vote_average.toFixed(1)}
            </span>
          </div>
        </div>
      `,
      )
      .join("");
  } catch (error) {
    console.log(error);
    moviesContainer.innerHTML = "<p>Erro ao carregar os filmes</p>";
  }
}

form.addEventListener("submit", (e) => {
  e.preventDefault();
  const term = searchInput.value.trim();
  if (term) {
    getMovies(SEARCH_API + encodeURIComponent(term));
  } else {
    getMovies(API_URL);
  }
});

getMovies();
