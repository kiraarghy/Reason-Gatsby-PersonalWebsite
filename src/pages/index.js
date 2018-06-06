import React from 'react'
import Link from 'gatsby-link'
import Header from '../../lib/js/src/components/header.bs.js'
import Footer from '../../lib/js/src/components/footer.bs.js'

const IndexPage = data => {
  console.log(data)
  return (
    <div>
      <Header data={data.data} />
	  <Footer data={data.data} />
    </div>
  )
}

export default IndexPage

export const query = graphql`
query blah {
	contentfulAbout {
	  name
	  portrait {
		description
		file {
		  url
		}
	  }
	  builtUsing {
		title
		file {
		  url
		}
	  }
	}
  }  
`
